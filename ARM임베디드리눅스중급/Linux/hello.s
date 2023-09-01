	.arch armv8-a
	.file	"hello.c"
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"hello world"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB0:
	stp	x29, x30, [sp, -16]!
.LCFI0:
	mov	x29, sp
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	puts
	nop
	ldp	x29, x30, [sp], 16
.LCFI1:
	ret
.LFE0:
	.size	main, .-main
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.4byte	.LECIE1-.LSCIE1
.LSCIE1:
	.4byte	0
	.byte	0x3
	.string	"zR"
	.uleb128 0x1
	.sleb128 -8
	.uleb128 0x1e
	.uleb128 0x1
	.byte	0x1b
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
.LECIE1:
.LSFDE1:
	.4byte	.LEFDE1-.LASFDE1
.LASFDE1:
	.4byte	.LASFDE1-.Lframe1
	.4byte	.LFB0-.
	.4byte	.LFE0-.LFB0
	.uleb128 0
	.byte	0x4
	.4byte	.LCFI0-.LFB0
	.byte	0xe
	.uleb128 0x10
	.byte	0x9d
	.uleb128 0x2
	.byte	0x9e
	.uleb128 0x1
	.byte	0x4
	.4byte	.LCFI1-.LCFI0
	.byte	0xde
	.byte	0xdd
	.byte	0xe
	.uleb128 0
	.align	3
.LEFDE1:
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
