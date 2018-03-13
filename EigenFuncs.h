#pragma once

/*--------------*/
/* EigenFuncs.h */
/*--------------*/
//#pragma once

extern "C" {

//識別子が定義されているか確認し、定義されていないなら、定義する
/*
#ifdef <識別子名>
<処理>
処理が複数行にわたる場合は、最後にendifを書く。

*/
/*
#defineは、以下を行っている。文字列の置き換えである。
機能 :文字列の置き換え
書式 :#define <文字列1> <文字列2>
*/
/*
__declspec(dllexport)は、エクスポート（DLLを作成）する際に必要。
__declspec(dllimport)は、インポートする際に必要。別のアプリからこれを読んだときに使う？
*/
/*
VisulaStudioにてコンパイルすす場合は、プリプロセッサに" EIGENFUNCS_EXPORTS"を設定する必要がある。
*/
#ifdef EIGENFUNCS_EXPORTS
#define EIGEN_FUNCS_API __declspec(dllexport)
#else //このelseはifdefに対するものだと考えられる。
#define EIGEN_FUNCS_API __declspec(dllimport)
#endif
	EIGEN_FUNCS_API void InverseMat(int dim_row, int dim_column, float a[], float ans[]);
	/*
	以下の一文は、インポートとエクスポート時に行頭がexportかimportに変化する。
	これが、DLLで外に見える関数となる？
	*/
	EIGEN_FUNCS_API void InnerProductMat(int dim_row1, int dim_column1, float mat1[], int dim_row2, int dim_column2, float mat2[], float ans[]);
	

	


/*
キーワードを定義して、間接的にエクスポートする（？）メリットは TEST_EXPORTSの定義されていないプロジェクトで このヘッダーがインクルードされたときに明らかになります。 
そのとき、_EXPORTイコール__declspec(dllimport)となり、 関数はインポートされるからです。
*/
} // extern "C"