int main(){

    struct list{
        int size=0;
        int* records = nullptr;

        void append(int x){
            int* new_array = new int[size + 1];

            for(int i=0; i<size; i++){
                new_array[i]=records[i];
            }
            new_array[size]=x;

            delete[] records;

            records= new_array;
            size++;
        }
    };
}