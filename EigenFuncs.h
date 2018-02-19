#pragma once

/*--------------*/
/* EigenFuncs.h */
/*--------------*/
//#pragma once

extern "C" {

//���ʎq����`����Ă��邩�m�F���A��`����Ă��Ȃ��Ȃ�A��`����
/*
#ifdef <���ʎq��>
<����>
�����������s�ɂ킽��ꍇ�́A�Ō��endif�������B

*/
/*
#define�́A�ȉ����s���Ă���B������̒u�������ł���B
�@�\ :������̒u������
���� :#define <������1> <������2>
*/
/*
__declspec(dllexport)�́A�G�N�X�|�[�g�iDLL���쐬�j����ۂɕK�v�B
__declspec(dllimport)�́A�C���|�[�g����ۂɕK�v�B�ʂ̃A�v�����炱���ǂ񂾂Ƃ��Ɏg���H
*/
/*
VisulaStudio�ɂăR���p�C�������ꍇ�́A�v���v���Z�b�T��" EIGENFUNCS_EXPORTS"��ݒ肷��K�v������B
*/
#ifdef EIGENFUNCS_EXPORTS
#define EIGEN_FUNCS_API __declspec(dllexport)
#else //����else��ifdef�ɑ΂�����̂��ƍl������B
#define EIGEN_FUNCS_API __declspec(dllimport)
#endif
	EIGEN_FUNCS_API void InverseMat_FullPivLU(int dim, float a[], float ans[]);
	/*
	�ȉ��̈ꕶ�́A�C���|�[�g�ƃG�N�X�|�[�g���ɍs����export��import�ɕω�����B
	���ꂪ�ADLL�ŊO�Ɍ�����֐��ƂȂ�H
	*/
	
/*
�L�[���[�h���`���āA�ԐړI�ɃG�N�X�|�[�g����i�H�j�����b�g�� TEST_EXPORTS�̒�`����Ă��Ȃ��v���W�F�N�g�� ���̃w�b�_�[���C���N���[�h���ꂽ�Ƃ��ɖ��炩�ɂȂ�܂��B 
���̂Ƃ��A_EXPORT�C�R�[��__declspec(dllimport)�ƂȂ�A �֐��̓C���|�[�g����邩��ł��B
*/
} // extern "C"