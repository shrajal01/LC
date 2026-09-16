class Solution {
public:
    string getHint(string secret, string guess) {
        int freqS[10] = {0};
        int freqG[10] = {0};

        int bulls = 0;

        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            }
            else {
                freqS[secret[i] - '0']++;
                freqG[guess[i] - '0']++;
            }
        }

        int cows = 0;

        for(int i = 0; i < 10; i++) {
            cows += min(freqS[i], freqG[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};