int divide(int dividend, int divisor) {
    //special cases
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;

    // transform to unsigned int
    bool sign = (dividend > 0)^(divisor > 0);
    unsigned int A = (divisor < 0) ? -divisor : divisor;
    unsigned int B = (dividend < 0) ? -dividend : dividend;
    int ret = 0;

    // shift 32 times
    for(int i = 31; i >= 0; i--)
    {
        if((B>>i) >= A)
        {
            ret = (ret<<1)|0x01;
            B -= (A<<i);   // update B
        }
        else
            ret = ret<<1;
    }

    if(sign)
        ret = -ret;

    return ret;
}
