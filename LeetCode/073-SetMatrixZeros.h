class Solution73 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag = false;      //������һ�еı�ʶλ
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i)       //���ñ�ʶλ
        {
            if (matrix[i][0] == 0)  flag = true;    //�����жϵ�һ�е����
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 0)    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = m - 1; i >= 0; --i)       //������ֵʱ����Ϊ��ʶλ�������Ͻǣ��������¶��ϸ���0ֵ
        {
            for (int j = n - 1; j >= 1; --j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (flag)    matrix[i][0] = 0;   //��һ��Ԫ�ص����ж�
        }
    }
};