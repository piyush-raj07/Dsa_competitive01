int precedence(char c) {
    if (c == '*' || c == '+')
        return 2;
    else if (c == '.')
        return 1;
    else
        return 0;
}