# fr_printf

{-0.} ==============================================[b2]
s = -<extra_spaces>.<output_len>
c = -<extra_spaces>.<no_efect>
[d/i/u/x/X/p] = -<extra_spaces>.<prefix_with_n_0>


{#}  ===============================================[b1]
[x/X] = prefix with 0x
{+}  ===============================================[b1]
[d/i/u/p] = prefix with +, override sp
s{p}  ==============================================[b1]
[d/i/u/p] = prefix with sp


==================================================[m]
[x/X] = hex conversion, overflow
[d/i] = dec/int conversion, overflow
[s/c] = unsigned str/char conversion, overflow
[u] = unsigned int conversion, overflow
[p] = unsigned #hex conversion, overflow


[%][flags][width].[precision][conversion]
1- check for % signe
2- check for flags [# +]
3- check for width [-0]
4- check for precision [.]
5- check for convesion [diuxXpsc%]
