void    p_hex(long int hex)
{
    char o;
    if(hex > 0)
    {
        p_hex(hex / 16);
        o = "0123456789abcdef"[hex % 16];
        write(1, &o, 1);
    }
}
void    p_adr(long int adr)
{
    write(1, "0x", 2);
    p_hex(adr);
}