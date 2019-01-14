.global rotate
#rdi = val
#rsi = num
#rdx = direction
#r10= 0
rotate:
	xor %r10, %r10
	cmp %rdx, %r10
	je right_shift
left_shift:
	rol $1, %rdi
	dec %rsi
	cmp %rsi, %r10
	je done 
	jmp left_shift
right_shift:
	ror $1, %rdi 
	dec %rsi
	cmp %rsi, %r10
	je done
	jmp right_shift
done:
	mov %rdi, %rax
	ret
