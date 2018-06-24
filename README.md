## Installation
#### If you have root permission
```shell
$ ./init.sh
```
**Linux users**: This bash script will install packages declared in: `./configs/install.Linux`

**Mac users**: This bash script will install packages declared in: `./configs/install.mac`

This script will backup your configure files in: `~/.setting_backup/`

This script will configure vim by using the repo: [vimrc](https://github.com/HansSJTU/vimrc)

#### If you do not have root permission
```shell
$ ./init_without_root.sh
```
This script will **not** install any packages

This script will **not** backup your configure files

This script will configure vim by using the repo: [vimrc](https://github.com/HansSJTU/vimrc)

## Bash Features
#### Themes
The color schema is from Dusk@Xcode.

**Linux users**: Colors will be automatically set by `init.sh`, but this will only effective for default terminal.

**Mac users**:  After running `init.sh`:
```shell
$ cd ./configs/macTerminalTheme
$ open Xcode_style.terminal

# following is not bash command
open termianl preference by: cmd + , 
click the Default in the lower left corner
```
Now, you should have the correct bash color theme for your mac terminal

#### Bash Functions
All bash functions are declared in `~/.bash_func`

#### Bash Alias
All bash aliases are declared in `~/.bash_alias`

## Tmux Features
Tmux shortcut are defined in `~/.tmux.conf`

## Vim Features
Vim configure is in `~/.vim_runtime`
Custom configure is in `~/.vim_runtime/my_configs.vim`
