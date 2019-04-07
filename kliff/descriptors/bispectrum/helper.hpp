#ifndef HELPER_H_
#define HELPER_H_

#include <cmath>
#include <cstddef>

// typedefs
typedef double   VectorOfSizeDIM[3];
typedef double   VectorOfSizeSix[6];


// 1D Array
//******************************************************************************
template<class T>
void AllocateAndInitialize1DArray(T*& arrayPtr, int const extent)
{
  arrayPtr = new T[extent];
  for (int i = 0; i < extent; ++i) {
    arrayPtr[i] = 0.0;
  }
}


// deallocate memory
template<class T>
void Deallocate1DArray(T*& arrayPtr)
{
  delete [] arrayPtr;
  // nullify pointer
  arrayPtr = NULL;
}


// 2D Array
//******************************************************************************
// allocate memory and set pointers
template<class T>
void AllocateAndInitialize2DArray(T**& arrayPtr, int const extentZero,
    int const extentOne)
{
  arrayPtr = new T*[extentZero];
  arrayPtr[0] = new T[extentZero * extentOne];
  for (int i = 1; i < extentZero; ++i) {
    arrayPtr[i] = arrayPtr[i - 1] + extentOne;
  }

  // initialize
  for (int i = 0; i < extentZero; ++i) {
    for (int j = 0; j < extentOne; ++j) {
      arrayPtr[i][j] = 0.0;
    }
  }
}


// deallocate memory
template<class T>
void Deallocate2DArray(T**& arrayPtr)
{
  if (arrayPtr != NULL) {
    delete [] arrayPtr[0];
  }
  delete [] arrayPtr;

  // nullify pointer
  arrayPtr = NULL;
}


// 3D Array
//******************************************************************************
// allocate memory and set pointers
template<class T>
void AllocateAndInitialize3DArray(T***& arrayPtr, int const extentZero,
    int const extentOne, int const extentTwo)
{
  arrayPtr = new T * *[extentZero];
  arrayPtr[0] = new T*[extentZero * extentOne];
  arrayPtr[0][0] = new T[extentZero * extentOne * extentTwo];

  for (int i = 1; i < extentZero; ++i) {
    arrayPtr[i] = arrayPtr[i - 1] + extentOne;
    arrayPtr[i][0] = arrayPtr[i - 1][0] + extentOne * extentTwo;
  }

  for (int i = 0; i < extentZero; ++i) {
    for (int j = 1; j < extentOne; ++j) {
      arrayPtr[i][j] = arrayPtr[i][j - 1] + extentTwo;
    }
  }

  // initialize
  for (int i = 0; i < extentZero; ++i) {
    for (int j = 0; j < extentOne; ++j) {
      for (int k = 0; k < extentTwo; ++k) {
        arrayPtr[i][j][k] = 0.0;
      }
    }
  }
}


// deallocate memory
template<class T>
void Deallocate3DArray(T***& arrayPtr)
{
  if (arrayPtr != NULL) {
    if (arrayPtr[0] != NULL) {
      delete [] arrayPtr[0][0];
    }
    delete [] arrayPtr[0];
  }
  delete [] arrayPtr;

  // nullify pointer
  arrayPtr = NULL;
}


// 4D Array  (the elements are not contiguous)
//******************************************************************************
// allocate memory and set pointers
template<class T>
void AllocateAndInitialize4DArray(T***& arrayPtr, int const extentZero,
    int const extentOne, int const extentTwo, int const extentThree)
{

  arrayPtr = new T ****[extentZero];
  for (int i = 0; i<extentZero; i++) {
    arrayPtr[i] = new T ***[extentOne];
    for (int j = 0; j<extentOne; j++) {
      arrayPtr[i][j] = new T **[extentTwo];
      for (int k = 0; k<extentTwo; k++) {
        arrayPtr[i][j][k] = new T *[extentThree];
        for (int l = 0; l<extentThree; l++) {
          arrayPtr[i][j][k][l] = 0.0;
        }
      }
    }
  }

}


// deallocate memory
template<class T>
void Deallocate4DArray(T***& arrayPtr)
{
  if (arrayPtr != NULL) {
    for (int i = 0; i<extentZero; i++) {
      if (arrayPtr[i] != NULL) {
        for (int j = 0; j<extentOne; j++) {
          if (arrayPtr[i][j] != NULL) {
            arrayPtr[i][j] = new T **[extentTwo];
            for (int k = 0; k<extentTwo; k++) {
              if (arrayPtr[i][j][k] != NULL) {
                arrayPtr[i][j][k] = new T *[extentThree];
                delete [] arrayPtr[i][j][k];
              }}
            delete [] arrayPtr[i][j];
          }}
        delete [] arrayPtr[i];
      }}
    delete [] arrayPtr;
  }

  // nullify pointer
  arrayPtr = NULL;
}




// 5D Array  (the elements are not contiguous)
//******************************************************************************
// allocate memory and set pointers
template<class T>
void AllocateAndInitialize5DArray(T***& arrayPtr, int const extentZero,
    int const extentOne, int const extentTwo, int const extentThree,
    int const extentFour)
{

  arrayPtr = new T ****[extentZero];
  for (int i = 0; i<extentZero; i++) {
    arrayPtr[i] = new T ***[extentOne];
    for (int j = 0; j<extentOne; j++) {
      arrayPtr[i][j] = new T **[extentTwo];
      for (int k = 0; k<extentTwo; k++) {
        arrayPtr[i][j][k] = new T *[extentThree];
        for (int l = 0; l<extentThree; l++) {
          arrayPtr[i][j][k][l] = new T [extentFour];
          for (int m = 0; m<extentFour; m++) {
            arrayPtr[i][j][k][l][m] = 0.0;
          }
        }
      }
    }
  }

}


// deallocate memory
template<class T>
void Deallocate5DArray(T***& arrayPtr)
{
  if (arrayPtr != NULL) {
    for (int i = 0; i<extentZero; i++) {
      if (arrayPtr[i] != NULL) {
        for (int j = 0; j<extentOne; j++) {
          if (arrayPtr[i][j] != NULL) {
            arrayPtr[i][j] = new T **[extentTwo];
            for (int k = 0; k<extentTwo; k++) {
              if (arrayPtr[i][j][k] != NULL) {
                arrayPtr[i][j][k] = new T *[extentThree];
                for (int l = 0; l<extentThree; l++) {
                  if (arrayPtr[i][j][k][l] != NULL) {
                    delete [] arrayPtr[i][j][k][l];
                  }}
                delete [] arrayPtr[i][j][k];
              }}
            delete [] arrayPtr[i][j];
          }}
        delete [] arrayPtr[i];
      }}
    delete [] arrayPtr;
  }

  // nullify pointer
  arrayPtr = NULL;
}



#endif // HELPER_H_
