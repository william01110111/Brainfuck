v is the input value
d is v over 10
i is iterations
m is v mod 10
r is v rounded to the nearset 

[
	v	0	0	0	0	0	0	0	0	0	0
	[>>+>+>+<<<<-]>>>>
	0	0	v	v	v	0	0	0	0	0	0
	[
		>++++++++++<
	0	0	v	v	v	10	0	0	0	0	0
		"divide.bf"
	0	0	v	v	d	0	0	0	0	0	0
		<<<+>>>
	0	1	v	v	d	0	0	0	0	0	0
	]<<<
	0	i	v	v	0	0	0	0	0	0	0
	-[
		>>>++++++++++<
	0	i	v	v	10	0	0	0	0	0	0
		"divide.bf"
	1	i	v	d	0	0	0	0	0	0	0
		<<<+>-
	]>>
	i	0	v	m	0	0	0	0	0	0	0
	[<<+>>>+<-]>
	i	m	v	0	m	0	0	0	0	0	0
	++++++++++++
	++++++++++++
	++++++++++++
	++++++++++++
	.[-]<<<<
	i	m	v	0	0	0	0	0	0	0	0
	[>[>>++++++++++<<-]>>[<<+>>-]<<<-]>>
	0	d	v	0	0	0	0	0	0	0	0
	[<<+>>-]<[<->-]<
]
