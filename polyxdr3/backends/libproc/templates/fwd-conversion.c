static double ${conv.name}(double inp)
{
:: if conv.bits > 0:
   double val = inp / (1 << ${conv.bits});
:: else:
   double val = inp;
:: #endif
:: if conv.equation == '':
   return val;
:: else:
   return ${conv.equation};
:: #endif
}

