#include "iworker.h"
#include "idatasource.h"
#include "filestorage.h"

template<typename N>
class MyReverse {
public:

    void getAnswer() {

        IWorker<N> Work(10);
        IDataSourceRead<N> S;
        IDataSourceWrite<N> Ans;
        IDataSourceRead<N> *S1 = &S;
        IDataSourceWrite<N> *Ans1 = &Ans;
        FileStorage<N> F;
        FileStorage<N> *F1 = &F;
        S.iDataOpen();
        Ans.iDataOpen();

        int files = 0;//how much files do we have
        int j;

        while (S.isEmpty()) {

            Work.getDataFromSourceToVector(S1);
            j = Work.data.size();
            for (int i = 0; i < j - i; i++)
                Work.data.swap(i, j - i);
            files++;
            Work.putDataToFile(F1);
        }

        for (int i = files - 1; i >= 0; i--) {
            Work.getDataFromFile(F1);
            Work.putDataToSourceFromVector(Ans1);
        }

    }

};


