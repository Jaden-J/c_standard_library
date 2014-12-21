
void float_tests(void)
{

   printf("FLT_RADIX= %i\n\n", FLT_RADIX);
    printf("DBL_DIG=        %5i         DBL_MANT_DIG =  %6i\n",
           DBL_DIG,DBL_MANT_DIG);
    printf("DBL_MAX_10_EXP= %5i         DBL_MAX_EXP  =  %6i\n",
           DBL_MAX_10_EXP, DBL_MAX_EXP);
    printf("DBL_MIN_10_EXP = %5i        DBL_MIN_EXP  =   %6i\n",
            DBL_MIN_10_EXP,  DBL_MIN_EXP);
    printf("           DBL_EPSILLON =   %le\n", DBL_EPSILON);
    printf("           DBL_MAX =        %le\n", DBL_MAX);
    printf("           DBL_MIN =        %le\n\n",DBL_MIN);
    printf("FLT_DIG=                %5i     FLT_MANT_DIG =   %6i\n",
           FLT_DIG, FLT_MANT_DIG);
    printf("FLT_MAX_10_EXP =        %5i     FLT_MAX_EXP  =   %6i\n",
           FLT_MAX_10_EXP,FLT_MAX_EXP);
    printf("FLT_MIN_10_EXP =        %5i     FLT_MIN_EXP  =   %6i\n",
           FLT_MAX_10_EXP, FLT_MAX_EXP);
    printf("          FLT_EPSILLON =   %e\n", FLT_EPSILON);
    printf("          FLT_MAX =        %e\n", FLT_MAX);
    printf("          FLT_MIN =        %e\n\n", FLT_MIN);
    radlog = log10(radix);
        /* test double properties */
        assert(10 <= DBL_DIG && FLT_DIG <= DBL_DIG);
        assert(DBL_EPSILON <= 1e-9);
        digs = (DBL_MANT_DIG - 1) * radlog;
        assert(digs <= DBL_DIG && DBL_DIG <= digs + 1);
//        assert(1e37 <= DBL_MAX);
        assert(37 <= DBL_MAX_10_EXP);
#if FLT_RADIX == 2
    assert(ldexp(1.0, DBL_MAX_EXP - 1) < DBL_MAX);
    assert(ldexp(1.0, DBL_MIN_EXP - 1) == DBL_MIN);
#endif // FLT_RADIX
}
