�m�W�G������
�Ǹ��Gb06901017
�t�šG�q���@

Compiler:C++11
IDE:Dev-c++ 5.11

��Purpose of these cpps and txts:
1.Generate_input_x.cpp is used to generate input_x.txt.
2.Generate_input_y.cpp is used to generate input_y.txt.
3.Generate_model.cpp is used to generate model.txt.
4.input_x.txt is the training datas used to represent the possibilities of tic_tac_toe board.
5.input_y.txt is the training datas that teach nueral network which step to take when encountering the situations in input_x.
6.model.txt describes the structure of neural network.
7.model_out.txt is the neural network after training.
8.model2.txt���Ӥp�a��Pmodel.txt���P�A����������Ӳv��model.txt�ٰ��A�ҥH��b�W���ɮפ�
9.model2_out.txt�O�S��train��model2(�ҥH��model2�@��)

��How to compile and execute:
1.Put hw6.cpp into HW06_b069001017 folder.
2.Open hw6.cpp and set up the parameters.
  (1)For model, I set learning rate 0.01, epoch 10, and batch size 100.(win rate 92%~93%)
  (2)For model2, �ڵo�{�ڧ�epoch�]��0(�����Strain)�A�]�X�ӴN�|���G��95%�Ӳv�A�M��train�L����Ӳv�N�|�U���A�ڤ]�����D������|�o��
3.Compile and run.

��How did I generate training data?
1.For input_x:
�ڥ���ѽL3^9�إi��ʥ����C�X�ӡA�M��R���Ҧ����i�઺���p�G���W���P�e�e�ƶq���@�˦h(�]��player�e�e����)�B����(���H�w�g�s�u�F)
�M��A���ݭn�����L���]�R���A�p�G�ѽL�u�Ѥ@�ӪŮ�H�Υ��骺���p(��馳�����G�Ӥe�e�S���󬡤G)
�ѤU���N�O�Ҧ�neural network�ݭn�|�U���L���F
2.For input_y:
�ڪ��Q�k�O�ھکҦ�input_x�������p�A�h�M�w�p�G�O�ڪ��ܷ|�U�b����a��
�p�G�L���ڤ観���󬡤G�A����M�N�����⥦�s�_��
�M�Ӧp�G�Ĥ観�@�Ӭ��G�ӧڤ�@�ӳ��S�����ɭԡA��M�N�@�w�n��Ĥ�צ�
���ۡA�p�G�W�z���p���S���o�͡A�ӧڤ観�a��O�i�H�s�y�����G���A����M�N�n�U�b���ءA�o�ˤU�@�^�X�N�i�H���
�̫�A�Y�W�z���󳣤����ߡA�S���ߧY���ӭt�����ɡA�ڧ⥦�������E�ӪŮ�B�C�ӪŮ���L�T�ت��p�h�Q�סA�]���C����}�l���L���i��ʸ��֡A�G�ڷQ�νa�|�N�i�H�d�w
���E�ӪŮ�A�]�N�O�@�}�l���ɭԡA�ڿ�ܤU�b�����A���M�U�b�����]���O����A���@�}�l�U�b����������|���Ĥ観���G�����|�A�ӥB�Ҷq��neural network���|�������ӧڵ���input_y�h�U�ѡA�ҥH��ܩM���v������A���Ӳv�۹���C�������U�k�A�H�Kneural network�@�B�����N�鱼�C��
���C�ӪŮ��(��e�U�U�@�l)�A�ڪ�����if-else�h�a�|�Ҧ����p�A�����өΰ��Ӳv�U�k�N�U����A�S�����ܴN�U����
��L�����p�ѩ��ܼƤӦh�A�ҥH�ڿ�ܥΦѮv�W�ұЪ��������(heuristic)�h�M�w�U�b���@�Ӧ�m�A���M�ڨS���@�@�ˬd�A���L�ڬ۫H���U�o�j����ڷ|������ܤK�E�����Q

�̫�ڪ�training data�@�@��2085��

��How did I disign neural network?
�ڪ��c�Q�G(�F�P�Ӧ۵������)
�Ĥ@�h�A���Ninput�h��One-hot encoding�ഫ��1(x)�B0.75(o)�B0(-)
�ĤG�h�A���O���C�B����B�﨤�u��xo-�[�_��(�ҥHx��o�V�h�A�Ʀr�V�j�A�Bx���񭫤�o��)
output�h�A�ھڨC�@��|������@��C�B���@����B���@�﨤�u���v�T�A�⨺�Ƿ|�v�T���Ƴ��[�_��(Ex�G���]�ڭ̬ݥ��W������A����|����Ĥ@��C�B�Ĥ@����Υ��W�k�U�ר����v�T)
���ҥH��x�]��1�Ao�]��0.75����]�A�O�]���u���סGx���G>o���G>�@��x>...

�M��model2�O�b���쥻model�ɡA���p�ߥ����F�@�ӼƦr�A�ҥH���g���S���ӧڷQ�����覡�s���A�S�Q��]�X�Ӫ����G���M���model�n�A�O�ګD�`��Y�A�ӥB��train�N�w�g���W���Ӳv�A�u�����D�O����쪺= =

~~~Appreciate TA for grading them~~~