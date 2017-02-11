set nu
let mapleader = "\<Space>"

vmap<leader>y y:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:!pbcopy < ~/.vimbuf<cr><cr>
nmap<leader>y yiw:!rm ~/.vbuf<cr><cr>:tabnew ~/.vbuf<cr>p:w<cr>:bdelete!<cr>:!pbcopy < ~/.vimbuf<cr><cr>
nmap<leader>p :r! cat ~/.vbuf<cr>
nmap<leader>d diwi
nmap<leader><leader>d diwdiwdiwdiw
