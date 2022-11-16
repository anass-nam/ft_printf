// {-0.} ==============================================[b2]
// s = -<extra spaces>.<output len>
// c = -<extra spaces>.<no efect>
// [d/i/u/x/X/p] = -<extra spaces>.<prefix with n 0>



// #  ===============================================[b1]
// [x/X] = prefix with 0x
// +  ===============================================[b1]
// [d/i/u/p] = prefix with +, override sp
// sp  ==============================================[b1]
// [d/i/u/p] = prefix with sp



// ==================================================[m]
// [x/X] = hex conversion, overflow
// [d/i] = dec/int conversion, overflow
// [s/c] = unsigned str/char conversion, overflow
// [u] = unsigned int conversion, overflow
// [p] = unsigned #hex conversion, overflow