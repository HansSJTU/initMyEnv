set nu
let mapleader = "\<Space>"
set cursorline
highlight Cursorline cterm=bold ctermbg=16 
set cmdheight=1

vmap<leader>y y:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:!pbcopy < ~/.vbuf<cr><cr>
nmap<leader>y yiw:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:!pbcopy < ~/.vbuf<cr><cr>
nmap<leader>yy yy:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>pggdd:w<cr>:bdelete!<cr>:!pbcopy < ~/.vbuf<cr><cr>
nmap<leader>p :r! cat ~/.vbuf<cr>
nmap<leader>o :only<cr>
nmap<leader>w <C-w>
nmap<leader>q :q<cr>
nmap<leader><leader>w :w<cr>
nmap<leader><leader>wq :wq<cr>
nmap<leader>d diwi
nmap<leader><leader>d diwdiwdiwdiw

map <silent> <leader>1 :diffget 1<CR>:diffupdate<CR>
map <silent> <leader>2 :diffget 2<CR>:diffupdate<CR>
map <silent> <leader>3 :diffget 3<CR>:diffupdate<CR>

set autochdir
set tags=tags;
map <silent><Leader>] <C-w><C-]><C-w>T
map <silent><leader>\ :vsp <CR>:exec("tag ".expand("<cword>"))<CR>
map <silent><leader>[ <C-w>}
map <silent><leader>t <C-t>
map <silent><leader>n :NERDTree<CR>
