;# evildragon
;# Copyright 2010      Jeff Garzik              <jgarzik@pobox.com>
;# Copyright 2012-2014 pooler                   <pooler@litecoinpool.org>
;# Copyright 2014      Lucas Jones              <https://github.com/lucasjones>
;# Copyright 2014-2016 Wolf9466                 <https://github.com/OhGodAPet>
;# Copyright 2016      Jay D Dee                <jayddee246@gmail.com>
;# Copyright 2017-2019 XMR-Stak                 <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
;# Copyright 2018      Lee Clagett              <https://github.com/vtnerd>
;# Copyright 2018-2019 tevador                  <tevador@gmail.com>
;# Copyright 2000      Transmeta Corporation    <https://github.com/intel/msr-tools>
;# Copyright 2004-2008 H. Peter Anvin           <https://github.com/intel/msr-tools>
;# Copyright 2018-2020 SChernykh                <https://github.com/SChernykh>
;# Copyright 2016-2020 evildragon                    <https://github.com/evildragon>, <support@evildragon.com>
;#
;#   This program is free software: you can redistribute it and/or modify
;#   it under the terms of the GNU General Public License as published by
;#   the Free Software Foundation, either version 3 of the License, or
;#   (at your option) any later version.
;#
;#   This program is distributed in the hope that it will be useful,
;#   but WITHOUT ANY WARRANTY; without even the implied warranty of
;#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
;#   GNU General Public License for more details.
;#
;#   You should have received a copy of the GNU General Public License
;#   along with this program. If not, see <http://www.gnu.org/licenses/>.
;#

.intel_syntax noprefix
#if defined(__APPLE__)
.text
#define DECL(x) _##x
#else
.section .text
#define DECL(x) x
#endif

#define ALIGN .balign
#define dq .quad

.global DECL(SHA3_256_AVX2_ASM)

ALIGN 64
DECL(SHA3_256_AVX2_ASM):

#include "sha3_256_avx2.inc"

KeccakF1600_AVX2_ASM:
	lea r8,[rip+rot_left+96]
	lea r9,[rip+rot_right+96]
	lea r10,[rip+rndc]

#include "sha3_256_keccakf1600_avx2.inc"

#if defined(__linux__) && defined(__ELF__)
.section .note.GNU-stack,"",%progbits
#endif
