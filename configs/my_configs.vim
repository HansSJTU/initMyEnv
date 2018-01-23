set nu
let mapleader = "\<Space>"
set cmdheight=1
set foldmethod=indent "set default foldmethod
set cursorline
highlight Cursorline cterm=bold ctermbg=16 

vmap<leader>y y:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:!pbcopy < ~/.vbuf<cr><cr>
nmap<leader>y yiw:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:!pbcopy < ~/.vbuf<cr><cr>
nmap<leader>yy yy:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>pggdd:w<cr>:bdelete!<cr>:!pbcopy < ~/.vbuf<cr><cr>
nmap<leader>p :r! cat ~/.vbuf<cr>
nmap<leader>o :only<cr>
nmap<leader>/ :noh<cr>
nmap<leader>w <C-w>
nmap<leader>q :q<cr>
nmap<leader><leader>w :w<cr>
nmap<leader><leader>wq :wq<cr>
nmap<leader>d diw
nmap<leader><leader>d diwdiwdiwdiw
nmap<C-a> 0
nmap<C-e> $
imap<C-e> <End>
imap<C-a> <Esc>0a<Esc>i

" if in diff mode, set as diff shortcut, else set as other
if &diff
    map <silent> <leader>1 :diffget 1<CR>:diffupdate<CR>
    map <silent> <leader>2 :diffget 2<CR>:diffupdate<CR>
    map <silent> <leader>3 :diffget 3<CR>:diffupdate<CR>
else
    map <silent><leader>1 1gt
    map <silent><leader>2 2gt
    map <silent><leader>3 3gt
    map <silent><leader>4 4gt
    map <silent><leader>5 5gt
    map <silent><leader>6 6gt
    map <silent><leader>7 7gt
    map <silent><leader>8 8gt
    map <silent><leader>9 9gt
endif

set autochdir
set tags=./tags;,tags;

function! GoToTagWithNewTab()
    :set noignorecase
    let tagWord = expand("<cword>")
    :tabe
    execute "tj ".expand(tagWord)

    let tagFilename = expand('%:t')
    if tagFilename == ''
        :tabclose
        :tabprevious
    else
        :silent! normal jzok
        :call HighLightCursor()
    endif
    :set ignorecase
endfunction

function! GoToTagWithNewSplit()
    :set noignorecase
    let tagWord = expand("<cword>")
    :vnew
    execute "tj ".expand(tagWord)

    let tagFilename = expand('%:t')
    if tagFilename == ''
        :q
    else
        :silent! normal jzok
        :call HighLightCursor()
    endif
    :set ignorecase
endfunction

function! HighLightCursor()
    :highlight Cursorline cterm=bold ctermbg=13
    redraw
    sleep 100m
    :highlight Cursorline cterm=bold ctermbg=16
    redraw
    sleep 100m
    :highlight Cursorline cterm=bold ctermbg=13
    redraw
    sleep 100m
    :highlight Cursorline cterm=bold ctermbg=16
    redraw
endfunction

map <silent><Leader>] :call GoToTagWithNewTab()<CR>
map <silent><leader>\ :call GoToTagWithNewSplit()<CR>
map <silent><leader>[ <C-w>}
map <silent><leader>t <C-w>T
map <silent><leader>n :NERDTree<CR>

map <silent><leader>f mtgd
map <silent><leader><leader>f mt<s-#>
map <silent><leader>g :noh<cr>`t :call HighLightCursor()<cr>
map <silent><leader>h :call HighLightCursor()<cr>

" bookmark
map <silent><leader>a ma
map <silent><leader><leader>a `azz :call HighLightCursor()<cr>

" run when start
autocmd VimEnter * call HighLightCursor()

" automatically paste without format
let &t_SI .= "\<Esc>[?2004h"
let &t_EI .= "\<Esc>[?2004l"

inoremap <special> <expr> <Esc>[200~ XTermPasteBegin()

function! XTermPasteBegin()
    set pastetoggle=<Esc>[201~
    set paste
    return ""
endfunction
