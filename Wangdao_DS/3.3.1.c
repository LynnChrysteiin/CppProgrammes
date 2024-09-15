#include "seq_stack.h"

bool parenthesis_matching(char expr[])
{
    SeqStack S;
    init_stack(S);
    char *p = expr;
    int tmp;
    while (*p != '\0')
    {
        switch (*p)
        {
        case '{':
            push(S, 1);
            break;
        case '[':
            push(S, 2);
            break;
        case '(':
            push(S, 3);
            break;
        case ')':
            pop(S, tmp);
            if (tmp != 3)
                return false;
            break;
        case ']':
            pop(S, tmp);
            if (tmp != 2)
                return false;
            break;
        case '}':
            pop(S, tmp);
            if (tmp != 1)
                return false;
            break;
        default:
            break;
        }
        p++;
    }
    if (!isEmpty(S))
        return false;
    return true;
}

int main()
{
    char expr[32] = "{2*[3*(4+5)]}+[5/(6+7)]";
    printf(parenthesis_matching(expr) ? "TRUE!" : "FALSE!");
    return 0;
}