set nu
let mapleader = "\<Space>"
set cmdheight=1
set foldmethod=indent "set default foldmethod
set cursorline
highlight Cursorline cterm=bold ctermbg=16 
set scrolloff=1
set swapfile
set shortmess=a
" set tabstop=2
" set shiftwidth=2
" set expandtab

" copy and paste
vmap<leader>y mby:silent exec "!rm ~/.vbuf"<cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:silent exec "!{ sed -z '$ s@\\n$@@' ~/.vbuf \| pbcopy; }" <cr>:redraw!<cr>`b
nmap<leader>y mbyiw:silent exec "!rm ~/.vbuf"<cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:silent exec "!{ sed -z '$ s@\\n$@@' ~/.vbuf \| pbcopy; }"<cr>:redraw!<cr>`b
nmap<leader>yy yy:silent exec "!rm ~/.vbuf"<cr>:tabnew ~/.vbuf<cr>pggdd:w<cr>:bdelete!<cr>:silent exec "!{ sed -z '$ s@\\n$@@' ~/.vbuf \| pbcopy; }"<cr>:redraw!<cr>
nmap<leader>yya mbvG$y:silent exec "!rm ~/.vbuf"<cr>:redraw!<cr>:tabnew ~/.vbuf<cr>pgg:w<cr>:bdelete!<cr>:silent exec "!{ sed -z '$ s@\\n$@@' ~/.vbuf \| pbcopy; }"<cr>:redraw!<cr>`b
nmap<leader>yyaa mbggvG$y:silent exec "!rm -f ~/.vbuf"<cr>:redraw!<cr>:tabnew ~/.vbuf<cr>pgg:w<cr>:bdelete!<cr>:silent exec "!{ sed -z '$ s@\\n$@@' ~/.vbuf \| pbcopy; }"<cr>:redraw!<cr>`b
nmap<leader>p :r! sed -z '$ s@\\n$@@' ~/.vbuf<cr>

" auxiliary
nmap<leader>u :diffupdate<cr>
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
vmap<C-a> 0
vmap<C-e> $
imap<C-e> <End>
imap<C-a> <Esc>0a<Esc>i
noremap <silent><leader>k <C-i>zz:call HighLightCursor()<cr>
noremap <silent><leader>j <C-o>zz:call HighLightCursor()<cr>

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

" set spell check
map <silent><Leader>c :set spell spelllang=en_us<CR>
autocmd BufRead,BufNewFile *.txt,*.md set spell spelllang=en_us

" set ycm 
" let g:ycm_global_ycm_extra_conf = "/Users/Hans/.vim_runtime/sources_forked/YouCompleteMe/.ycm_extra_conf.py"
" let g:ycm_add_preview_to_completeopt = 0
" let g:ycm_show_diagnostics_ui = 0
" let g:ycm_server_log_level = 'info'
" let g:ycm_min_num_identifier_candidate_chars = 2
" let g:ycm_collect_identifiers_from_comments_and_strings = 1
" let g:ycm_complete_in_strings=1
" let g:ycm_key_invoke_completion = '<c-z>'
" set completeopt=menu,menuone
" 
" noremap <c-z> <NOP>
" 
" let g:ycm_semantic_triggers =  {
" 			\ 'c,cpp,cu,python,java,go,erlang,perl': ['re!\w{2}'],
" 			\ 'cs,lua,javascript': ['re!\w{2}'],
" 			\ }
" let g:ycm_filetype_whitelist = { 
" 			\ "c":1,
" 			\ "cpp":1, 
" 			\ "py":1,
" 			\ "sh":1,
" 			\ "zsh":1,
" 			\ "cu":1,
" 			\ }

" automatically paste without format
let &t_SI .= "\<Esc>[?2004h"
let &t_EI .= "\<Esc>[?2004l"

inoremap <special> <expr> <Esc>[200~ XTermPasteBegin()

function! XTermPasteBegin()
    set pastetoggle=<Esc>[201~
    set paste
    return ""
endfunction

" Commenting blocks of code.
autocmd FileType c,cpp,cu,java,scala let b:comment_leader = '// '
autocmd FileType sh,ruby,python   let b:comment_leader = '# '
autocmd FileType conf,fstab       let b:comment_leader = '# '
autocmd FileType tex              let b:comment_leader = '% '
autocmd FileType mail             let b:comment_leader = '> '
autocmd FileType vim              let b:comment_leader = '" '
noremap <silent><leader>. mb:<C-B>silent <C-E>s/^/<C-R>=escape(b:comment_leader,'\/')<CR>/<CR>:nohlsearch<CR>`blll
noremap <silent><leader>, mb:<C-B>silent <C-E>s/^\V<C-R>=escape(b:comment_leader,'\/')<CR>//e<CR>:nohlsearch<CR>`b

" For smooth motion
if v:version < 705 " Version less than 7.04.15 does not support
    let g:comfortable_motion_no_default_key_mappings = 1
else
    let g:comfortable_motion_scroll_down_key = "j"
    let g:comfortable_motion_scroll_up_key = "k"
    let g:comfortable_motion_no_default_key_mappings = 1
    let g:comfortable_motion_impulse_multiplier = 1  " Feel free to increase/decrease this value.
    nnoremap <silent> <C-d> :call comfortable_motion#flick(g:comfortable_motion_impulse_multiplier * winheight(0) * 2)<CR>
    nnoremap <silent> <C-u> :call comfortable_motion#flick(g:comfortable_motion_impulse_multiplier * winheight(0) * -2)<CR>
endif

" For move between split window
nnoremap <silent> fh <C-w>h
nnoremap <silent> fj <C-w>j
nnoremap <silent> fk <C-w>k
nnoremap <silent> fl <C-w>l

" Relative line number
set number relativenumber
augroup numbertoggle
  autocmd!
  autocmd BufEnter,FocusGained,InsertLeave * set relativenumber
  autocmd BufLeave,FocusLost,InsertEnter   * set norelativenumber
augroup END
