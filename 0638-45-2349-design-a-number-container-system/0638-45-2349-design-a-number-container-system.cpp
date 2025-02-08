class NumberContainers {
private:
    unordered_map<int, int> indmp;
    unordered_map<int, set<int>> nummp;

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (indmp.find(index) != indmp.end()) {
            int prevnum = indmp[index];
            if (prevnum == number)
                return;
            nummp[prevnum].erase(index);
            if (nummp[prevnum].empty()) {
                nummp.erase(prevnum);
            }
        }
        indmp[index] = number;
        nummp[number].insert(index);
    }

    int find(int number) {
        if (nummp.find(number) != nummp.end()) {
            return *nummp[number].begin();
        }
        return -1;
    }
};