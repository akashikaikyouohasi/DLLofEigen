// DllEigen.cpp : Defines the exported functions for the DLL application.
//


//#define EIGENFUNCS_EXPORTS

/*
EIGENFUNCS_EXPORTSの定義されていないプロジェクトで このヘッダーがインクルードされたときに明らかになります。
そのとき、EIGEN_FUNCS_APIイコール__declspec(dllimport)となり、 関数はインポートされるからです。
*/

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/LU>
#include "EigenFuncs.h"



//Eigenの通すパスは、解答したフォルダの一番上。わざわざsrcを参照する必要はない。

/*
DLLはダイナミックリンクライブラリのこと。関数の共有ライブラリとして機能する実行ファイル。
メモリ内のDLLは複数のアプリからアクセス可能。
スタティックリンクライブラリは、各アプリケーションがビルドしてロードする必要がある。
異なる言語で書かれていても、関数の呼び出し規約に従う限り、使用することができる。

DLLにはエクスポートテーブルがある。エクスポートテーブルに記載されたエクスポート関数のみが、別の実行形式にアクセスが可能。
エクスポート方法は２つ：__stdcall規約を使うこと
（１）モジュール定義ファイル.defを作成し、それをもとにDLLをビルドする。
（２）関数の定義に、__declspec(dllexport)キーワードを使う。.defファイルは不要。



*/

/*
extern
複数ソースコードをまたいで変数やメソッドを使用するときに時に使います。
全ファイル中のどれかに定義されている 宣言だけを行い定義は行わない宣言方法です
*/
extern "C" {
	EIGEN_FUNCS_API void InverseMat(int dim_row, int dim_column, float a[], float ans[]) {
		/*
		逆行列を演算する関数
		[入力]
		dim_row:行数
		dim_column:列数
		a:行列の配列 dim_row×dim_column 行毎に格納している
			１行１列, 1行2列, １行３列, ２行１列, ２行２列, 2行３列....
		[出力]
		ans:計算した逆行列
		*/

		//dim次元の２次元行列作成
		Eigen::MatrixXf mat = Eigen::MatrixXf::Zero(dim_row, dim_column);

		//引数で与えられた配列を２次元行列に格納
		int count = 0;
		for (int c = 0; c < dim_row; c++) {
			for (int r = 0; r < dim_column; r++) {
				mat(c, r) = a[count];
				count++;
			}
		}

		//逆行列を計算
		//inverseは遅いらしい？
		Eigen::MatrixXf InvMat = mat.inverse();

		//計算した２次元逆行列を１次元配列に入れなおして返す
		count = 0;
		for (int c = 0; c < dim_row; c++) {
			for (int r = 0; r < dim_column; r++) {
				ans[count] = InvMat(c, r);
				count++;
			}
		}
	}

	EIGEN_FUNCS_API void InnerProductMat(int dim_row1, int dim_column1, float arr1[], int dim_row2, int dim_column2, float arr2[], float ans[]) {
		/*
		行列を２つ受け取り内積を演算する関数
		[入力]
		dim_row:行数
		dim_column:列数
		arr:行列の配列 dim_row×dim_column 行毎に格納している
			１行１列, 1行2列, １行３列, ２行１列, ２行２列, 2行３列....
		[出力]
		ans:計算した逆行列
		*/


		//２次元行列作成
		Eigen::MatrixXf mat1 = Eigen::MatrixXf::Zero(dim_row1, dim_column1);
		Eigen::MatrixXf mat2 = Eigen::MatrixXf::Zero(dim_row2, dim_column2);


		//引数で与えられた配列を２次元行列に格納
		int count = 0;
		for (int c = 0; c < dim_row1; c++) {
			for (int r = 0; r < dim_column1; r++) {
				mat1(c, r) = arr1[count];
				count++;
			}
		}
		count = 0;
		for (int c = 0; c < dim_row2; c++) {
			for (int r = 0; r < dim_column2; r++) {
				mat2(c, r) = arr2[count];
				count++;
			}
		}

		//内積を計算
		Eigen::MatrixXf resultMat = mat1*mat2;

		//計算した２次元逆行列を１次元配列に入れなおして返す
		count = 0;
		for (int c = 0; c < dim_row1; c++) {
			for (int r = 0; r < dim_column2; r++) {
				ans[count] = resultMat(c, r);
				count++;
			}
		}
	}
} // extern "C"