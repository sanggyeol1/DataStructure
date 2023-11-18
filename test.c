#include <stdio.h>

is_full(s) {
	if (스택의 원소수 == size) return TRUE;
	else return FALSE;
}

is_empty(s) {
	if (스택의 원소수 == 0) return TRUE;
	else return FALSE;
}

push(s, item) {
	if (is_full(s)) return ERROR_STACKFULL;
	else 스택의 맨 위에item을 추가한다.
}

pop(s) {
	if (is_empty(s))return ERROR_SRACKEMPTY;
	else 스택의 맨 위의 원소를 제거하여 반환한다.
}

peak(s) {
	if (is_empty(s)) {
		return ERROR_STACKEMPTY;
	else 스택의 맨 위의 원소를 제거하지 않고 반환한다.
	}
}

is_empty(s): 스택이 공백상태인지 검사
is_full(s): 스택이 포화상태인지 검사
create():스택을 생성
peak(s): 요소를 스택에서 삭제하지 않고 보기만 하는 연산
(참고)pop연산은 요소를 스택에서 완전히 삭제하면서 가져온다.

1차원 배열 stack[]
	스택에서 가장 최근에 입력되었던 자료를 가리키는 top변수
	가장 먼저 들어온 요소는 stack[0]에, 가장 최근에 들어온 요소는 stack[top]에 저장
	스택이 공백상태이면 top은 -1

is_empty(S):
	if top == -1
		then return TRUE
		else return FALSE

is_full(S):
	if top == (MAX_STACK_SIZE-1)
		then return TRUE
		else return FALSE

push(S, x)
if is_full(S) {
	then error "overflow"
else top<-top +1
stack[top]<-x
}

pop(S, x)
if (is_empty(s)) {
	then error "underflow"
else e <- stack[top]
	top <- top -1
	return e
}



