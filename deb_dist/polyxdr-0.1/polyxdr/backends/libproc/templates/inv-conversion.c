static double ${conv.name}(double val)
{
:: if conv.equation == '':
   double outp = val;
:: else:
   double outp = ${conv.equation};
:: #endif
:: if conv.bits > 0:
   return outp * (1 << ${conv.bits});
:: else:
   return outp;
:: #endif
}

