# fr_printf

{-0.} ==============================================[b2] <br>
s = -<extra_spaces>.<output_len><br>
c = -<extra_spaces>.<no_efect><br>
[d/i/u/x/X/p] = -<extra_spaces>.<prefix_with_n_0><br>
<br>
<br>
{#}  ===============================================[b1]<br>
[x/X] = prefix with 0x<br>
{+}  ===============================================[b1]<br>
[d/i/u/p] = prefix with +, override sp<br>
s{p}  ==============================================[b1]<br>
[d/i/u/p] = prefix with sp<br>
<br>
<br>
==================================================[m]<br>
[x/X] = hex conversion, overflow<br>
[d/i] = dec/int conversion, overflow<br>
[s/c] = unsigned str/char conversion, overflow<br>
[u] = unsigned int conversion, overflow<br>
[p] = unsigned #hex conversion, overflow<br>
<br>
<br>
[%][flags][width].[precision][conversion]<br>
1- check for % signe<br>
2- check for flags [# +]<br>
3- check for width [-0]<br>
4- check for precision [.]<br>
5- check for convesion [diuxXpsc%]<br>
<br>
