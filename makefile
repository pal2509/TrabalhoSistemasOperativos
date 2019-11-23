interpretador: lex.yy.c
	gcc lex.yy.c -o interpretador -lfl

lex.yy.c: interpretador.l
	flex interpretador.l