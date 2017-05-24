set nu
let mapleader = "\<Space>"
set cursorline
highlight Cursorline cterm=bold ctermbg=8 
set cmdheight=1

vmap<leader>y y:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:!pbcopy < ~/.vbuf<cr><cr>
nmap<leader>y yiw:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:!pbcopy < ~/.vbuf<cr><cr>
nmap<leader>p :r! cat ~/.vbuf<cr>
nmap<leader>d diwi
nmap<leader><leader>d diwdiwdiwdiw
