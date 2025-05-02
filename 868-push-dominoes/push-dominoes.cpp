class Solution {
public:
    string pushDominoes(string dominoes) {
        size_t num_of_dominoes = dominoes.size();
        int last_right = -1, last_left = 0;

        for (size_t i = 0; i < num_of_dominoes; ++i) {
            char c = dominoes[i];

            if (c == 'R') {
                if (last_right != -1) {
                    for (size_t r = last_right + 1; r < i; ++r) {
                        dominoes[r] = 'R';
                    }
                }
                last_right = i;
            } else if (c == 'L') {
                if (last_right != -1) {
                    for (size_t left_p = last_right + 1, right_p = i - 1;
                         left_p < right_p; left_p++, right_p--) {
                        dominoes[left_p] = 'R';
                        dominoes[right_p] = 'L';
                    }
                    last_right = -1;
                } else {
                    for (size_t l = last_left; l < i; ++l) {
                        dominoes[l] = 'L';
                    }
                }
                last_left = i;
            }
        }

        if (last_right != -1) {
            for (int i = last_right + 1; i < num_of_dominoes; ++i) {
                dominoes[i] = 'R';
            }
        }

        return dominoes;
    }
};