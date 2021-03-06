/* bMassType:  0=AVG, 1=MONO */
/* element values from http://physics.nist.gov/PhysRefData/Compositions/index.html */

#define PROTON_MASS 1.00727646688

/*
 * bMassType=0 for average masses
 * bMassType=1 for monoisotopic masses
 */
void INITIALIZE_MASS(double *pdAAMass,
        int bMassType)
{
   double H=0.0,
          O=0.0,
          C=0.0,
          N=0.0,
          P=0.0,
          S=0.0;
   int i;

   for (i=0; i<128; i++)
      pdAAMass[i] = 999999.9;

   if (bMassType)
   {
      H = pdAAMass['h'] =  1.0078250352;  /* hydrogen */
      O = pdAAMass['o'] = 15.99491463;   /* oxygen */
      C = pdAAMass['c'] = 12.0000000;      /* carbon */
      N = pdAAMass['n'] = 14.003074;   /* nitrogen */
      P = pdAAMass['p'] = 30.973762;     /* phosphorus */
      S = pdAAMass['s'] = 31.9720707;     /* sulphur */
   }
   else  /* average masses */
   {
      H = pdAAMass['h'] =  1.00794;  /* hydrogen */
      O = pdAAMass['o'] = 15.9994;   /* oxygen */
      C = pdAAMass['c'] = 12.0107;   /* carbon */
      N = pdAAMass['n'] = 14.0067;   /* nitrogen */
      P = pdAAMass['p'] = 30.973761; /* phosporus */
      S = pdAAMass['s'] = 32.065;    /* sulphur */
   }

   pdAAMass['G'] = C*2  + H*3  + N   + O ;
   pdAAMass['A'] = C*3  + H*5  + N   + O ;
   pdAAMass['S'] = C*3  + H*5  + N   + O*2 ;
   pdAAMass['P'] = C*5  + H*7  + N   + O ;
   pdAAMass['V'] = C*5  + H*9  + N   + O ;
   pdAAMass['T'] = C*4  + H*7  + N   + O*2 ;
   pdAAMass['C'] = C*3  + H*5  + N   + O   + S ;
   pdAAMass['L'] = C*6  + H*11 + N   + O ;
   pdAAMass['I'] = C*6  + H*11 + N   + O ;
   pdAAMass['N'] = C*4  + H*6  + N*2 + O*2 ;
   pdAAMass['D'] = C*4  + H*5  + N   + O*3 ;
   pdAAMass['Q'] = C*5  + H*8  + N*2 + O*2 ;
   pdAAMass['K'] = C*6  + H*12 + N*2 + O ;
   pdAAMass['E'] = C*5  + H*7  + N   + O*3 ;
   pdAAMass['M'] = C*5  + H*9  + N   + O   + S ;
   pdAAMass['H'] = C*6  + H*7  + N*3 + O ;
   pdAAMass['F'] = C*9  + H*9  + N   + O ;
   pdAAMass['R'] = C*6  + H*12 + N*4 + O ;
   pdAAMass['Y'] = C*9  + H*9  + N   + O*2 ;
   pdAAMass['W'] = C*11 + H*10 + N*2 + O ;

   pdAAMass['O'] = C*5  + H*12 + N*2 + O*2 ;
   pdAAMass['X'] = pdAAMass['L'];  /* treat X as L or I for no good reason */
   pdAAMass['B'] = (pdAAMass['N'] + pdAAMass['D']) / 2.0;  /* treat B as average of N and D */
   pdAAMass['Z'] = (pdAAMass['Q'] + pdAAMass['E']) / 2.0;  /* treat Z as average of Q and E */

} /*ASSIGN_MASS*/
