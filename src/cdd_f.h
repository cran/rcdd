/* automatically generated by sed scripts from the c source named below: */
/* cdd.h: Header file for cddlib.c 
   written by Komei Fukuda, fukuda@ifor.math.ethz.ch
   Version 0.94f, February 7, 2008
*/

/* cddlib.c : C-Implementation of the double description method for
   computing all vertices and extreme rays of the polyhedron 
   P= {x :  b - A x >= 0}.  
   Please read COPYING (GNU General Public Licence) and
   the manual cddlibman.tex for detail.
*/

#ifndef  CDDLIB_CDD_HF
#define  CDDLIB_CDD_HF

#ifndef  CDDLIB_CDDMP_HF
#include "cddmp_f.h"
#endif  /* CDDLIB_CDDMP_HF */

#ifndef  CDDLIB_CDDTYPES_HF
#include "cddtypes_f.h"
#endif  /* CDDLIB_CDDTYPES_HF */

#ifdef ddf_GMPRATIONAL
#ifndef CDDLIB_CDD_HF
#include "cdd_f.h"
#endif
#endif

/* GLOBAL CONSTANTS and STATISTICS VARIABLES (to be set by ddf_set_global_constants() */
extern myfloat ddf_zero;
extern myfloat ddf_one;
extern myfloat ddf_purezero;
extern myfloat ddf_minuszero;
extern myfloat ddf_minusone;
// Added by Charlie
void ddf_set_global_constants(void);
void ddf_free_global_constants(void);

extern time_t ddf_statStartTime; /* cddlib starting time */
extern long ddf_statBApivots;  /* basis finding pivots */
extern long ddf_statCCpivots;  /* criss-cross pivots */
extern long ddf_statDS1pivots; /* phase 1 pivots */
extern long ddf_statDS2pivots; /* phase 2 pivots */
extern long ddf_statACpivots;  /* anticycling (cc) pivots */
#ifdef ddf_GMPRATIONAL
extern long ddf_statBSpivots;  /* basis status checking pivots */
#endif
extern ddf_LPSolverType ddf_choiceLPSolverDefault;  /* Default LP solver Algorithm */
extern ddf_LPSolverType ddf_choiceRedcheckAlgorithm;  /* Redundancy Checking Algorithm */
extern ddf_boolean ddf_choiceLexicoPivotQ;    /* whether to use the lexicographic pivot */

   /* to be used to avoid creating temporary spaces for myfloat */
#define ddf_almostzero  1.0E-7

/* ---------- FUNCTIONS MEANT TO BE PUBLIC ---------- */

#if defined(__cplusplus)
extern "C" {
#endif

/* basic matrix manipulations */
void ddf_InitializeArow(ddf_colrange,ddf_Arow *);
void ddf_InitializeAmatrix(ddf_rowrange,ddf_colrange,ddf_Amatrix *);
void ddf_InitializeBmatrix(ddf_colrange, ddf_Bmatrix *);
ddf_SetFamilyPtr ddf_CreateSetFamily(ddf_bigrange,ddf_bigrange);
void ddf_FreeSetFamily(ddf_SetFamilyPtr);
ddf_MatrixPtr ddf_CreateMatrix(ddf_rowrange,ddf_colrange);
void ddf_FreeAmatrix(ddf_rowrange,ddf_colrange,ddf_Amatrix);
void ddf_FreeArow(ddf_colrange, ddf_Arow);
void ddf_FreeBmatrix(ddf_colrange,ddf_Bmatrix);
void ddf_FreeDDMemory(ddf_PolyhedraPtr);
void ddf_FreePolyhedra(ddf_PolyhedraPtr);
void ddf_FreeMatrix(ddf_MatrixPtr);
void ddf_SetToIdentity(ddf_colrange, ddf_Bmatrix);

/* sign recognitions */
ddf_boolean ddf_Nonnegative(myfloat);
ddf_boolean ddf_Nonpositive(myfloat);
ddf_boolean ddf_Positive(myfloat);
ddf_boolean ddf_Negative(myfloat);
ddf_boolean ddf_EqualToZero(myfloat);
ddf_boolean ddf_Nonzero(myfloat);
ddf_boolean ddf_Equal(myfloat,myfloat);
ddf_boolean ddf_Larger(myfloat,myfloat);
ddf_boolean ddf_Smaller(myfloat,myfloat);
void ddf_abs(myfloat, myfloat);
void ddf_LinearComb(myfloat, myfloat, myfloat, myfloat, myfloat);
void ddf_InnerProduct(myfloat, ddf_colrange, ddf_Arow, ddf_Arow);

/* major cddlib operations */
ddf_MatrixPtr ddf_CopyInput(ddf_PolyhedraPtr);
ddf_MatrixPtr ddf_CopyOutput(ddf_PolyhedraPtr);
ddf_MatrixPtr ddf_CopyInequalities(ddf_PolyhedraPtr);
ddf_MatrixPtr ddf_CopyGenerators(ddf_PolyhedraPtr);
ddf_SetFamilyPtr ddf_CopyIncidence(ddf_PolyhedraPtr);
ddf_SetFamilyPtr ddf_CopyAdjacency(ddf_PolyhedraPtr);
ddf_SetFamilyPtr ddf_CopyInputIncidence(ddf_PolyhedraPtr);
ddf_SetFamilyPtr ddf_CopyInputAdjacency(ddf_PolyhedraPtr);
ddf_boolean ddf_DDFile2File(char *ifile, char *ofile, ddf_ErrorType *err);
ddf_boolean ddf_DDInputAppend(ddf_PolyhedraPtr*, ddf_MatrixPtr, ddf_ErrorType*);
ddf_MatrixPtr ddf_PolyFile2Matrix(FILE *f, ddf_ErrorType *);

ddf_PolyhedraPtr ddf_DDMatrix2Poly(ddf_MatrixPtr, ddf_ErrorType *);
ddf_PolyhedraPtr ddf_DDMatrix2Poly2(ddf_MatrixPtr, ddf_RowOrderType, ddf_ErrorType *);
ddf_boolean ddf_Redundant(ddf_MatrixPtr, ddf_rowrange, ddf_Arow, ddf_ErrorType *);  /* 092 */
ddf_rowset ddf_RedundantRows(ddf_MatrixPtr, ddf_ErrorType *);  /* 092 */
ddf_boolean ddf_SRedundant(ddf_MatrixPtr, ddf_rowrange, ddf_Arow, ddf_ErrorType *);  /* 093a */
ddf_rowset ddf_SRedundantRows(ddf_MatrixPtr, ddf_ErrorType *);  /* 093a */
ddf_rowset ddf_RedundantRowsViaShooting(ddf_MatrixPtr, ddf_ErrorType *); /* 092 */
ddf_rowrange ddf_RayShooting(ddf_MatrixPtr, ddf_Arow intpt, ddf_Arow direction);  /* 092 */ 
 /* 092, find the first inequality "hit" by a ray from an intpt.  */
ddf_boolean ddf_ImplicitLinearity(ddf_MatrixPtr, ddf_rowrange, ddf_Arow, ddf_ErrorType *);  /* 092 */
ddf_rowset ddf_ImplicitLinearityRows(ddf_MatrixPtr, ddf_ErrorType *);  /* 092  */
int ddf_FreeOfImplicitLinearity(ddf_MatrixPtr, ddf_Arow, ddf_rowset *, ddf_ErrorType *) ; /* 094 */
ddf_boolean ddf_MatrixCanonicalizeLinearity(ddf_MatrixPtr *, ddf_rowset *,ddf_rowindex *, ddf_ErrorType *); /* 094 */
ddf_boolean ddf_MatrixCanonicalize(ddf_MatrixPtr *, ddf_rowset *, ddf_rowset *, ddf_rowindex *, ddf_ErrorType *); /* 094 */
ddf_boolean ddf_MatrixRedundancyRemove(ddf_MatrixPtr *M, ddf_rowset *redset,ddf_rowindex *newpos, ddf_ErrorType *); /* 094 */
ddf_boolean ddf_FindRelativeInterior(ddf_MatrixPtr, ddf_rowset *, ddf_rowset *, ddf_LPSolutionPtr *, ddf_ErrorType *);  /* 094 */
ddf_boolean ddf_ExistsRestrictedFace(ddf_MatrixPtr, ddf_rowset, ddf_rowset, ddf_ErrorType *);  /* 0.94 */
ddf_boolean ddf_ExistsRestrictedFace2(ddf_MatrixPtr, ddf_rowset, ddf_rowset, ddf_LPSolutionPtr *, ddf_ErrorType *); /* 0.94 */

ddf_SetFamilyPtr ddf_Matrix2Adjacency(ddf_MatrixPtr, ddf_ErrorType *);  /* 093 */
ddf_SetFamilyPtr ddf_Matrix2WeakAdjacency(ddf_MatrixPtr, ddf_ErrorType *);  /* 093a */
long ddf_MatrixRank(ddf_MatrixPtr, ddf_rowset, ddf_colset, ddf_rowset *, ddf_colset *);

/* Matrix Basic Operations */
ddf_MatrixPtr ddf_MatrixCopy(ddf_MatrixPtr); /* a new name for ddf_CopyMatrix */
ddf_MatrixPtr ddf_CopyMatrix(ddf_MatrixPtr); /* 090c, kept for compatibility */
ddf_MatrixPtr ddf_MatrixNormalizedCopy(ddf_MatrixPtr); /* 094 */
ddf_MatrixPtr ddf_MatrixNormalizedSortedCopy(ddf_MatrixPtr,ddf_rowindex*); /* 094 */
ddf_MatrixPtr ddf_MatrixUniqueCopy(ddf_MatrixPtr,ddf_rowindex*); /* 094 */
ddf_MatrixPtr ddf_MatrixNormalizedSortedUniqueCopy(ddf_MatrixPtr,ddf_rowindex*); /* 094 */
ddf_MatrixPtr ddf_MatrixSortedUniqueCopy(ddf_MatrixPtr,ddf_rowindex*); /* 094 */

ddf_MatrixPtr ddf_MatrixAppend(ddf_MatrixPtr, ddf_MatrixPtr);  /* a name for ddf_AppendMatrix */
ddf_MatrixPtr ddf_AppendMatrix(ddf_MatrixPtr, ddf_MatrixPtr);  /* 090c, kept for compatibility */

int ddf_MatrixAppendTo(ddf_MatrixPtr*, ddf_MatrixPtr);  /* 092 */
int ddf_Remove(ddf_MatrixPtr*, ddf_rowrange);  /* 092 */
ddf_MatrixPtr ddf_MatrixSubmatrix(ddf_MatrixPtr, ddf_rowset delset); /* 092 */
ddf_MatrixPtr ddf_MatrixSubmatrix2(ddf_MatrixPtr, ddf_rowset delset,ddf_rowindex*); /* 094.  It returns new row positions. */
ddf_MatrixPtr ddf_MatrixSubmatrix2L(ddf_MatrixPtr, ddf_rowset delset,ddf_rowindex*); /* 094.  Linearity shifted up. */
int ddf_MatrixShiftupLinearity(ddf_MatrixPtr *,ddf_rowindex *); /* 094 */
int ddf_MatrixRowRemove(ddf_MatrixPtr *M, ddf_rowrange r); /* 092 */
int ddf_MatrixRowRemove2(ddf_MatrixPtr *M, ddf_rowrange r,ddf_rowindex*); /* 094*/
int ddf_MatrixRowsRemove(ddf_MatrixPtr *M, ddf_rowset delset); /* 094 */
int ddf_MatrixRowsRemove2(ddf_MatrixPtr *M, ddf_rowset delset,ddf_rowindex*); /* 094 */

/* input/output */
void ddf_SetInputFile(FILE **f,ddf_DataFileType inputfile, ddf_ErrorType *);
void ddf_SetWriteFileName(ddf_DataFileType, ddf_DataFileType, char, ddf_RepresentationType);

void ddf_WriteAmatrix(FILE *, ddf_Amatrix, ddf_rowrange, ddf_colrange);
void ddf_WriteArow(FILE *f, ddf_Arow a, ddf_colrange);
void ddf_WriteBmatrix(FILE *, ddf_colrange, ddf_Bmatrix T);
void ddf_WriteMatrix(FILE *, ddf_MatrixPtr);
void ddf_MatrixIntegerFilter(ddf_MatrixPtr);
void ddf_WriteReal(FILE *, myfloat);
void ddf_WriteNumber(FILE *f, myfloat x); 
    /* write a number depending on the arithmetic used.  */
void ddf_WritePolyFile(FILE *, ddf_PolyhedraPtr);
void ddf_WriteRunningMode(FILE *, ddf_PolyhedraPtr);
void ddf_WriteErrorMessages(FILE *, ddf_ErrorType);
void ddf_WriteSetFamily(FILE *, ddf_SetFamilyPtr);
void ddf_WriteSetFamilyCompressed(FILE *, ddf_SetFamilyPtr);
void ddf_WriteProgramDescription(FILE *);
void ddf_WriteDDTimes(FILE *, ddf_PolyhedraPtr);
void ddf_WriteTimes(FILE *, time_t, time_t);
void ddf_WriteIncidence(FILE *, ddf_PolyhedraPtr);
void ddf_WriteAdjacency(FILE *, ddf_PolyhedraPtr);
void ddf_WriteInputAdjacency(FILE *, ddf_PolyhedraPtr);
void ddf_WriteInputIncidence(FILE *, ddf_PolyhedraPtr);

/* functions and types for LP solving */

ddf_LPPtr ddf_Matrix2LP(ddf_MatrixPtr, ddf_ErrorType *);
  /* Load a matrix to create an LP object. */
  
ddf_LPPtr ddf_Matrix2Feasibility(ddf_MatrixPtr, ddf_ErrorType *);
  /* Load a matrix to create an LP object for feasibility (obj == 0) .*/  /*  094 */
  
ddf_LPPtr ddf_Matrix2Feasibility2(ddf_MatrixPtr, ddf_rowset, ddf_rowset, ddf_ErrorType *);
  /* Load a matrix to create an LP object for feasibility with additional equality and
   strict inequality constraints. */  /*  094 */

ddf_boolean ddf_LPSolve(ddf_LPPtr,ddf_LPSolverType,ddf_ErrorType *);
ddf_boolean ddf_LPSolve0(ddf_LPPtr,ddf_LPSolverType,ddf_ErrorType *);
void ddf_CrissCrossSolve(ddf_LPPtr lp,ddf_ErrorType *);
void ddf_DualSimplexSolve(ddf_LPPtr lp,ddf_ErrorType *);

ddf_LPPtr ddf_MakeLPforInteriorFinding(ddf_LPPtr);  
ddf_LPSolutionPtr ddf_CopyLPSolution(ddf_LPPtr);  /* 0.90c */
void ddf_WriteLP(FILE *, ddf_LPPtr); /* 092 */

ddf_LPPtr ddf_CreateLPData(ddf_LPObjectiveType,ddf_NumberType,ddf_rowrange,ddf_colrange);
int ddf_LPReverseRow(ddf_LPPtr, ddf_rowrange);
    /* reverse the i-th row (1 <= i <= no. of rows) */
int ddf_LPReplaceRow(ddf_LPPtr, ddf_rowrange, ddf_Arow);
    /* replace the i-th row (1 <= i <= no. of rows) */
ddf_Arow ddf_LPCopyRow(ddf_LPPtr, ddf_rowrange);
    /* copy the i-th row (1 <= i <= no. of rows) */

void ddf_FreeLPData(ddf_LPPtr);
void ddf_FreeLPSolution(ddf_LPSolutionPtr);

void ddf_WriteLPResult(FILE *, ddf_LPPtr, ddf_ErrorType);
void ddf_WriteLPErrorMessages(FILE *, ddf_ErrorType);
void ddf_WriteLPTimes(FILE *, ddf_LPPtr);
void ddf_WriteLPStats(FILE *f);
void ddf_WriteLPMode(FILE *f);

ddf_MatrixPtr ddf_FourierElimination(ddf_MatrixPtr,ddf_ErrorType *);
ddf_MatrixPtr ddf_BlockElimination(ddf_MatrixPtr, ddf_colset, ddf_ErrorType *);

#if defined(__cplusplus)
}
#endif

/* ---------- FUNCTIONS MEANT TO BE NON-PUBLIC ---------- */
void ddf_QuickSort(ddf_rowindex, long, long, ddf_Amatrix, long);
void ddf_RandomPermutation(ddf_rowindex, long, unsigned int seed);
void ddf_UniqueRows(ddf_rowindex, long, long, ddf_Amatrix, long, ddf_rowset, long *);

ddf_boolean ddf_DoubleDescription(ddf_PolyhedraPtr, ddf_ErrorType*);
ddf_boolean ddf_DoubleDescription2(ddf_PolyhedraPtr, ddf_RowOrderType, ddf_ErrorType *);

void ddf_FreeDDMemory0(ddf_ConePtr);
void ddf_fread_rational_value (FILE *f, myfloat value);
void ddf_sread_rational_value (char *s, myfloat value);
void ddf_AddNewHalfspace1(ddf_ConePtr, ddf_rowrange);
void ddf_AddNewHalfspace2(ddf_ConePtr, ddf_rowrange);
void ddf_AddRay(ddf_ConePtr, myfloat *);
void ddf_AddArtificialRay(ddf_ConePtr);
void ddf_AValue(myfloat*,ddf_colrange, ddf_Amatrix, myfloat *, ddf_rowrange);
void ddf_CheckAdjacency(ddf_ConePtr, ddf_RayPtr*, ddf_RayPtr*, ddf_boolean *);
void ddf_CheckEquality(ddf_colrange, ddf_RayPtr *, ddf_RayPtr *, ddf_boolean *);
void ddf_ComputeRowOrderVector(ddf_ConePtr);
void ddf_ConditionalAddEdge(ddf_ConePtr,ddf_RayPtr, ddf_RayPtr, ddf_RayPtr);
void ddf_CopyArow(myfloat *, myfloat *, ddf_colrange);
void ddf_CopyNormalizedAmatrix(myfloat **, myfloat **, ddf_rowrange, ddf_colrange);
void ddf_CopyNormalizedArow(myfloat *, myfloat *, ddf_colrange);
void ddf_CopyAmatrix(myfloat **, myfloat **, ddf_rowrange, ddf_colrange);
void ddf_PermuteCopyAmatrix(myfloat **, myfloat **, ddf_rowrange, ddf_colrange, ddf_rowindex);
void ddf_PermutePartialCopyAmatrix(myfloat **, myfloat **, ddf_rowrange, ddf_colrange, ddf_rowindex,ddf_rowrange, ddf_rowrange);
void ddf_CopyBmatrix(ddf_colrange, ddf_Bmatrix T, ddf_Bmatrix TCOPY);
void ddf_CopyRay(myfloat *, ddf_colrange, ddf_RayPtr,
   ddf_RepresentationType, ddf_colindex);
void ddf_CreateInitialEdges(ddf_ConePtr);
void ddf_CreateNewRay(ddf_ConePtr, ddf_RayPtr, ddf_RayPtr, ddf_rowrange);
void ddf_Eliminate(ddf_ConePtr, ddf_RayPtr*);
void ddf_EvaluateARay1(ddf_rowrange, ddf_ConePtr);
void ddf_EvaluateARay2(ddf_rowrange, ddf_ConePtr);
void ddf_FeasibilityIndices(long *, long *, ddf_rowrange, ddf_ConePtr);
void ddf_FindBasis(ddf_ConePtr, long *rank);
void ddf_FindInitialRays(ddf_ConePtr, ddf_boolean *);
void ddf_ColumnReduce(ddf_ConePtr);
void ddf_GaussianColumnPivot(ddf_rowrange, ddf_colrange, ddf_Amatrix, ddf_Bmatrix,  ddf_rowrange, ddf_colrange);
ddf_boolean ddf_LexSmaller(myfloat *, myfloat *, long);
ddf_boolean ddf_LexLarger(myfloat *, myfloat *, long);
ddf_boolean ddf_LexEqual(myfloat *, myfloat *, long);
void ddf_Normalize(ddf_colrange, myfloat *);
void ddf_MatrixIntegerFilter(ddf_MatrixPtr);
void ddf_ProcessCommandLine(FILE*,ddf_MatrixPtr, char *);
void ddf_SelectNextHalfspace(ddf_ConePtr, ddf_rowset, ddf_rowrange *);
void ddf_SelectPivot2(ddf_rowrange,ddf_colrange,ddf_Amatrix,
ddf_Bmatrix,ddf_RowOrderType,ddf_rowindex, ddf_rowset,ddf_rowrange,ddf_rowset,
ddf_colset,ddf_rowrange *,ddf_colrange *,ddf_boolean *);
void ddf_SelectPreorderedNext(ddf_ConePtr, ddf_rowset, ddf_rowrange *);
void ddf_SetInequalitySets(ddf_ConePtr);
void ddf_SnapToInteger(myfloat, myfloat);
void ddf_StoreRay1(ddf_ConePtr, myfloat *, ddf_boolean *);
void ddf_StoreRay2(ddf_ConePtr, myfloat *, ddf_boolean *, ddf_boolean *);
void ddf_TableauEntry(myfloat *, ddf_rowrange, ddf_colrange, ddf_Amatrix, ddf_Bmatrix T, ddf_rowrange, ddf_colrange);
void ddf_UpdateEdges(ddf_ConePtr, ddf_RayPtr, ddf_RayPtr);
void ddf_UpdateRowOrderVector(ddf_ConePtr, ddf_rowset PriorityRows);
void ddf_WriteRay(FILE *, ddf_colrange, ddf_RayPtr,
   ddf_RepresentationType, ddf_colindex);
void ddf_ZeroIndexSet(ddf_rowrange, ddf_colrange, ddf_Amatrix, myfloat *, ddf_rowset);

/* New functions to handle data loading, NON-PUBLIC */
ddf_NumberType ddf_GetNumberType(char *);
ddf_ConePtr ddf_ConeDataLoad(ddf_PolyhedraPtr);
ddf_PolyhedraPtr ddf_CreatePolyhedraData(ddf_rowrange, ddf_colrange);
ddf_boolean ddf_InitializeConeData(ddf_rowrange, ddf_colrange, ddf_ConePtr*);
ddf_boolean ddf_AppendMatrix2Poly(ddf_PolyhedraPtr*, ddf_MatrixPtr);





/* end of cddlib.h */

#endif  /* CDDLIB_CDD_HF */

