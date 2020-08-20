let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +37 wgrep.c
badd +15 Makefile
badd +5 pruebaConHola
badd +608 term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//22397:/bin/zsh
badd +3 pruebaSinHola
badd +0 term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//32069:/bin/zsh
argglobal
%argdel
$argadd wgrep.c
$argadd Makefile
edit wgrep.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 119 + 119) / 239)
exe '2resize ' . ((&lines * 33 + 34) / 69)
exe 'vert 2resize ' . ((&columns * 119 + 119) / 239)
exe '3resize ' . ((&lines * 33 + 34) / 69)
exe 'vert 3resize ' . ((&columns * 119 + 119) / 239)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 38 - ((13 * winheight(0) + 33) / 67)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
38
normal! 032|
wincmd w
argglobal
if bufexists("term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//32069:/bin/zsh") | buffer term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//32069:/bin/zsh | else | edit term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//32069:/bin/zsh | endif
if &buftype ==# 'terminal'
  silent file term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//32069:/bin/zsh
endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 14 - ((13 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
14
normal! 022|
wincmd w
argglobal
if bufexists("term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//22397:/bin/zsh") | buffer term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//22397:/bin/zsh | else | edit term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//22397:/bin/zsh | endif
if &buftype ==# 'terminal'
  silent file term://~/Documents/Code/OSTEP/ostep-projects/initial-utilities/wgrep//22397:/bin/zsh
endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 579 - ((1 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
579
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 119 + 119) / 239)
exe '2resize ' . ((&lines * 33 + 34) / 69)
exe 'vert 2resize ' . ((&columns * 119 + 119) / 239)
exe '3resize ' . ((&lines * 33 + 34) / 69)
exe 'vert 3resize ' . ((&columns * 119 + 119) / 239)
tabnext 1
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=filnxtToOF
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
