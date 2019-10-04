set nocompatible              " 这是必需的 
filetype off                  " 这是必需的 

" 在此设置运行时路径 
set tabstop=4
set rtp+=~/.vim/bundle/Vundle.vim
let g:ycm_global_ycm_extra_conf='~/.ycm_extra_conf.py'

let g:ycm_confirm_extra_conf = 0
" YouCompleteMe
" Python Semantic Completion
let g:ycm_python_binary_path = '/usr/bin/python3'
" C family Completion Path
let g:ycm_global_ycm_extra_conf='~/.ycm_extra_conf.py'
" 跳转快捷键
 nnoremap <c-k> :YcmCompleter GoToDeclaration<CR>|
 nnoremap <c-h> :YcmCompleter GoToDefinition<CR>| 
 nnoremap <c-j> :YcmCompleter GoToDefinitionElseDeclaration<CR>|
 " 停止提示是否载入本地ycm_extra_conf文件
 let g:ycm_confirm_extra_conf = 0
 " 语法关键字补全
 let g:ycm_seed_identifiers_with_syntax = 1
 " 开启 YCM 基于标签引擎
 let g:ycm_collect_identifiers_from_tags_files = 1
" 从第2个键入字符就开始罗列匹配项
 let g:ycm_min_num_of_chars_for_completion=2
 " 在注释输入中也能补全
 let g:ycm_complete_in_comments = 1
 " 在字符串输入中也能补全
 let g:ycm_complete_in_strings = 1
 " 注释和字符串中的文字也会被收入补全
 let g:ycm_collect_identifiers_from_comments_and_strings = 1
 " 弹出列表时选择第1项的快捷键(默认为<TAB>和<Down>)
 let g:ycm_key_list_select_completion = ['<C-n>', '<Down>']
 " 弹出列表时选择前1项的快捷键(默认为<S-TAB>和<UP>)
 let g:ycm_key_list_previous_completion = ['<C-p>', '<Up>']
 " 主动补全, 默认为<C-Space>
 "let g:ycm_key_invoke_completion = ['<C-Space>']
 " 停止显示补全列表(防止列表影响视野), 可以按<C-Space>重新弹出
 "let g:ycm_key_list_stop_completion = ['<C-y>']

" vundle初始化 
call vundle#begin()
" 或者传递一个 Vundle 安装插件的路径
"call vundle#begin('~/some/path/here')

" 让 Vundle 管理 Vundle, 必须
Plugin 'VundleVim/Vundle.vim'

" 下面是不同支持幅度的例子
" 保持 Plugin 命令 在 vundle#begin 和 end 之间
" plugin 在 GitHub 仓库
Plugin 'tpope/vim-fugitive'
" 来自http://vim-scripts.org/vim/scripts.html的插件 
" Plugin 'L9'
" 未托管在GitHub上的Git插件 
" Plugin 'git://git.wincent.com/command-t.git'
" 本地机器上的git软件库（即编写自己的插件时） 
" Plugin 'file:///home/gmarik/path/to/plugin'
" sparkup vim脚本在名为vim的该软件库子目录下。 
" 传递路径，合理设置运行时路径。 
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" 安装 L9 并避免名称冲突 
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': newL9'}
Plugin 'Valloric/YouCompleteMe'
Plugin 'SirVer/ultisnips'
Plugin 'honza/vim-snippets'

"每个插件都应该在这一行之前  
call vundle#end()            " 这是必需的 
filetype plugin indent on    " 这是必需的 
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
