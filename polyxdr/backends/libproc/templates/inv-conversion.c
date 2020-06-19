static double ${conv.name}(double val)
{
:: if conv.equation == '':
   double outp = val;
:: else:
   double outp = ${conv.equation};
:: #endif
:: if conv.offset != 0:
   outp -= ${conv.offset};
:: #endif
:: if conv.divisor != 0:
   return outp * ${conv.divisor};
:: else:
   return outp;
:: #endif
}

