#include <stdio.h>

is_full(s) {
	if (������ ���Ҽ� == size) return TRUE;
	else return FALSE;
}

is_empty(s) {
	if (������ ���Ҽ� == 0) return TRUE;
	else return FALSE;
}

push(s, item) {
	if (is_full(s)) return ERROR_STACKFULL;
	else ������ �� ����item�� �߰��Ѵ�.
}

pop(s) {
	if (is_empty(s))return ERROR_SRACKEMPTY;
	else ������ �� ���� ���Ҹ� �����Ͽ� ��ȯ�Ѵ�.
}

peak(s) {
	if (is_empty(s)) {
		return ERROR_STACKEMPTY;
	else ������ �� ���� ���Ҹ� �������� �ʰ� ��ȯ�Ѵ�.
	}
}

is_empty(s): ������ ����������� �˻�
is_full(s): ������ ��ȭ�������� �˻�
create():������ ����
peak(s): ��Ҹ� ���ÿ��� �������� �ʰ� ���⸸ �ϴ� ����
(����)pop������ ��Ҹ� ���ÿ��� ������ �����ϸ鼭 �����´�.

1���� �迭 stack[]
	���ÿ��� ���� �ֱٿ� �ԷµǾ��� �ڷḦ ����Ű�� top����
	���� ���� ���� ��Ҵ� stack[0]��, ���� �ֱٿ� ���� ��Ҵ� stack[top]�� ����
	������ ��������̸� top�� -1

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



