static double ${conv.name}(double inp)
{
   double val = inp;
:: if conv.divisor != 1:
   val = inp / ${conv.divisor};
:: #endif
:: if conv.offset != 0:
   val += ${conv.offset};
:: #endif
:: if conv.equation == '':
   return val;
:: else:
   return ${conv.equation};
:: #endif
}

