#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include "Song.h"
using namespace std;

class Data{
    public:
        vector<Song> data = vector<Song>(145174);

        Data(){
            ifstream ifs;
            string tmp;
            int rank;
            int streams;
            string date;
            string id;
            string name;
            string country;
            string genre;
            string par;
            int count = 0;
            ifs.open("StreamingData.csv");
            getline(ifs, tmp);

            while(getline(ifs,tmp))
                istringstream ss(tmp);
                par = "";
                getline(ss,par,',');
                rank = stoi(par);
                getline(ss,par,',');
                id = par;
                getline(ss,par,',');
                streams = stoi(par);
                getline(ss,par,',');
                name = par;
                getline(ss,par,',');
                country = par;
                getline(ss,par,',');
                genre = par;
                getline(ss,par,',');
                date = par;
            }
                Song s = Song(rank,id,streams,name,country,genre,date);
                data[count] = s;
                count++;
        }

        // This function handles all the data retrieving without needing to access the other ones.
        vector<Song> getSortedData(string category, string type){
            if(type == "radix"){
                if(category == "rank"){
                    radixSortRank(data);
                    return data;
                }
                else if(category == "id"){
                    radixSortID(data);
                    return data;
                }
                else if(category == "streams"){
                    radixSortStreams(data);
                    return data;
                }
                else if(category == "name"){
                    radixSortName(data);
                    return data;
                }
                else if(category == "country"){
                    radixSortCountry(data);
                    return data;
                }
                else if(category == "genre"){
                    radixSortGenre(data);
                    return data;
                }
                else if(category == "date"){
                    radixSortDate(data);
                    return data;
                }
            }
            else if(type == "quick"){
                if(category == "rank"){
                    quickSortRank(data,0,145173);
                    return data;
                }
                else if(category == "id"){
                    quickSortID(data,0,145173);
                    return data;
                }
                else if(category == "streams"){
                    quickSortStreams(data,0,145173);
                    return data;
                }
                else if(category == "name"){
                    quickSortName(data,0,145173);
                    return data;
                }
                else if(category == "country"){
                    quickSortCountry(data,0,145173);
                    return data;
                }
                else if(category == "genre"){
                    quickSortGenre(data,0,145173);
                    return data;
                }
                else if(category == "date"){
                    quickSortDate(data,0,145173);
                    return data;
                }

            }
        }

        // All functions after this point until the marker are relating to radix sort
        void countingSortRank(vector<Song> &arr, int place){
            vector<Song> out = vector<Song>(145174);
            int countArr[10];

            for(int i =0; i<10; i++){
                countArr[i] = 0;
            }

            for(int j=0; j<145174; j++){
                countArr[(arr[j].getRank() / place)%10]++;
            }

            for(int k=0; k<10; k++){
                if(k!=0){
                    countArr[k]+=countArr[k-1];
                }
            }

            for(int m=0; m<145174; m++){
                int x = (arr[m].getRank() / place)%10;
                countArr[x]--;
                out[countArr[x]] = arr[m];
            }

            for(int n=0; n<145174; n++){
                arr[n] = out[n];
            }
        }


        void radixSortRank(vector<Song> &arr){
            int max = 0;
            cout<<"1"<<endl;
            for(int i=0; i<145174; i++){
                cout<<"1.5"<<endl;
                if(arr[i].getRank() > max){
                    cout<<arr[i].getRank()<<endl;
                    max = arr[i].getRank();
                }
            }
            cout<<"2"<<endl;

            for(int j=1; max/j>0; j*=10){
                countingSortRank(arr,j);
            }
        }

        void countingSortStreams(vector<Song> &arr, int place){
            vector<Song> out = vector<Song>(145174);
            int countArr[10];

            for(int i =0; i<10; i++){
                countArr[i] = 0;
            }

            for(int j=0; j<145174; j++){
                countArr[(arr[j].getStreams() / place)%10]++;
            }

            for(int k=0; k<10; k++){
                if(k!=0){
                    countArr[k]+=countArr[k-1];
                }
            }

            for(int m=0; m<145174; m++){
                int x = (arr[m].getStreams() / place)%10;
                countArr[x]--;
                out[countArr[x]] = arr[m];
            }

            for(int n=0; n<145174; n++){
                arr[n] = out[n];
            }
        }


        void radixSortStreams(vector<Song> &arr){
            int max = 0;
            for(int i=0; i<145174; i++){
                if(arr[i].getStreams()>max){
                    max = arr[i].getStreams();
                }
            }

            for(int j=1; max/j>0; j*=10){
                countingSortStreams(arr,j);
            }
        }

        void countingSortDate(vector<Song> &arr, int place){
            vector<Song> out = vector<Song>(145174);
            int countArr[10];

            for(int i =0; i<10; i++){
                countArr[i] = 0;
            }

            for(int j=0; j<145174; j++){
                countArr[(arr[j].getDate() / place)%10]++;
            }

            for(int k=0; k<10; k++){
                if(k!=0){
                    countArr[k]+=countArr[k-1];
                }
            }

            for(int m=0; m<145174; m++){
                int x = (arr[m].getDate() / place)%10;
                countArr[x]--;
                out[countArr[x]] = arr[m];
            }

            for(int n=0; n<145174; n++){
                arr[n] = out[n];
            }
        }


        void radixSortDate(vector<Song> &arr){
            int max = 0;
            for(int i=0; i<145174; i++){
                if(arr[i].getDate()>max){
                    max = arr[i].getDate();
                }
            }

            for(int j=1; max/j>0; j*=10){
                countingSortDate(arr,j);
            }
        }

        int val(char c){
            if(c<0){
                return c+256;
            }
            else{
                return c;
            }
        }

        void countingSortID(vector<Song> &arr, int place){
            vector<Song> out = vector<Song>(145174);
            int countArr[256];

            for(int i =0; i<256; i++){
                countArr[i] = 0;
            }

            for(int j=0; j<145174; j++){
                if(arr[j].getID().length()-1 >= place){
                    countArr[val(arr[j].getID()[place])]++;
                }
                else{
                    countArr[0]++;
                }
            }

            for(int k=0; k<256; k++){
                if(k!=0){
                    countArr[k]+=countArr[k-1];
                }
            }

            for(int m=0; m<145174; m++){
                int x = val(arr[m].getID()[place]);
                countArr[x]--;
                out[countArr[x]] = arr[m];
            }

            for(int n=0; n<145174; n++){
                arr[n] = out[n];
            }
        }

        void radixSortID(vector<Song> &arr){
            string max_string;
            for(int i=0; i<145174; i++){
                if(arr[i].getID() > max_string){
                    max_string = arr[i].getID();
                }
            }

            for(int j=0; j<max_string.length(); j++){
                countingSortID(arr, j);
            }
        }

        void countingSortName(vector<Song> &arr, int place){
            vector<Song> out = vector<Song>(145174);
            int countArr[256];

            for(int i =0; i<256; i++){
                countArr[i] = 0;
            }

            for(int j=0; j<145174; j++){
                if(arr[j].getName().length()-1 >= place){
                    countArr[val(arr[j].getName()[place])]++;
                }
                else{
                    countArr[0]++;
                }
            }

            for(int k=0; k<256; k++){
                if(k!=0){
                    countArr[k]+=countArr[k-1];
                }
            }

            for(int m=0; m<145174; m++){
                int x = val(arr[m].getName()[place]);
                countArr[x]--;
                out[countArr[x]] = arr[m];
            }

            for(int n=0; n<145174; n++){
                arr[n] = out[n];
            }
        }

        void radixSortName(vector<Song> &arr){
            string max_string;
            for(int i=0; i<145174; i++){
                if(arr[i].getName() > max_string){
                    max_string = arr[i].getName();
                }
            }

            for(int j=0; j<max_string.length(); j++){
                countingSortName(arr, j);
            }
        }

        void countingSortCountry(vector<Song> &arr, int place){
            vector<Song> out = vector<Song>(145174);
            int countArr[256];

            for(int i =0; i<256; i++){
                countArr[i] = 0;
            }

            for(int j=0; j<145174; j++){
                if(arr[j].getCountry().length()-1 >= place){
                    countArr[val(arr[j].getCountry()[place])]++;
                }
                else{
                    countArr[0]++;
                }
            }

            for(int k=0; k<10; k++){
                if(k!=0){
                    countArr[k]+=countArr[k-1];
                }
            }

            for(int m=0; m<145174; m++){
                int x = val(arr[m].getCountry()[place]);
                countArr[x]--;
                out[countArr[x]] = arr[m];
            }

            for(int n=0; n<145174; n++){
                arr[n] = out[n];
            }
        }

        void radixSortCountry(vector<Song> &arr){
            string max_string;
            for(int i=0; i<145174; i++){
                if(arr[i].getCountry() > max_string){
                    max_string = arr[i].getCountry();
                }
            }

            for(int j=0; j<max_string.length(); j++){
                countingSortCountry(arr, j);
            }
        }

        void countingSortGenre(vector<Song> &arr, int place){
            vector<Song> out = vector<Song>(145174);
            int countArr[256];

            for(int i =0; i<256; i++){
                countArr[i] = 0;
            }

            for(int j=0; j<145174; j++){
                if(arr[j].getGenre().length()-1 >= place){
                    countArr[val(arr[j].getGenre()[place])]++;
                }
                else{
                    countArr[0]++;
                }
            }

            for(int k=0; k<10; k++){
                if(k!=0){
                    countArr[k]+=countArr[k-1];
                }
            }

            for(int m=0; m<145174; m++){
                int x = val(arr[m].getGenre()[place]);
                countArr[x]--;
                out[x] = arr[m];
            }

            for(int n=0; n<145174; n++){
                arr[n] = out[n];
            }
        }

        void radixSortGenre(vector<Song> &arr){
            string max_string;
            for(int i=0; i<145174; i++){
                if(arr[i].getGenre() > max_string){
                    max_string = arr[i].getGenre();
                }
            }

            for(int j=0; j<max_string.length(); j++){
                countingSortGenre(arr, j);
            }
        }

        // All functions after this point are for quick sort
        void swap(Song *a, Song *b){
            Song c = *a;
            *a = *b;
            *b = c;
        }
        
        int partitionRank(vector<Song> &arr, int low, int high){
            int pivot = arr[high].getRank(); // pivot
            int i = (low - 1); // Index of smaller element and indicates
                        // the right position of pivot found so far

            for (int j = low; j <= high - 1; j++) {
                // If current element is smaller than the pivot
                if (arr[j].getRank() < pivot) {
                    i++; // increment index of smaller element
                    swap(&arr[i], &arr[j]);
                }
            }

            swap(&arr[i + 1], &arr[high]);
            return (i + 1);
        }

        int partitionStreams(vector<Song> &arr, int low, int high){
            int pivot = arr[high].getStreams(); // pivot
            int i = (low - 1); // Index of smaller element and indicates
                        // the right position of pivot found so far

            for (int j = low; j <= high - 1; j++) {
                // If current element is smaller than the pivot
                if (arr[j].getStreams() < pivot) {
                    i++; // increment index of smaller element
                    swap(&arr[i], &arr[j]);
                }
            }
            
            swap(&arr[i + 1], &arr[high]);
            return (i + 1);
        }

        int partitionDate(vector<Song> &arr, int low, int high){
            int pivot = arr[high].getDate(); // pivot
            int i = (low - 1); // Index of smaller element and indicates
                        // the right position of pivot found so far

            for (int j = low; j <= high - 1; j++) {
                // If current element is smaller than the pivot
                if (arr[j].getDate() < pivot) {
                    i++; // increment index of smaller element
                    swap(&arr[i], &arr[j]);
                }
            }
            
            swap(&arr[i + 1], &arr[high]);
            return (i + 1);
        }

        void quickSortRank(vector<Song> &arr, int low, int high){
            if (low < high) {
                /* pi is partitioning index, arr[p] is now at right place */
                int pi = partitionRank(arr, low, high);

                // Separately sort elements before
                // partition and after partition
                quickSortRank(arr, low, pi - 1);
                quickSortRank(arr, pi + 1, high);
            }
        }

        void quickSortStreams(vector<Song> &arr, int low, int high){
            if (low < high) {
                /* pi is partitioning index, arr[p] is now at right place */
                int pi = partitionStreams(arr, low, high);

                // Separately sort elements before
                // partition and after partition
                quickSortStreams(arr, low, pi - 1);
                quickSortStreams(arr, pi + 1, high);
            }
        }

        void quickSortDate(vector<Song> &arr, int low, int high){
            if (low < high) {
                /* pi is partitioning index, arr[p] is now at right place */
                int pi = partitionDate(arr, low, high);

                // Separately sort elements before
                // partition and after partition
                quickSortDate(arr, low, pi - 1);
                quickSortDate (arr, pi + 1, high);
            }
        }

        void quickSortID(vector<Song> &arr, int left, int right){ 
            int p = left, q = right;
            string mid = arr[(left + right) / 2].getID();

            // partition 
            while (p <= q){
                while (arr[p].getID() < mid)
                    p++;
                while (arr[q].getID() > mid)
                    q--;
                if (p <= q) {
                    swap(&arr[p], &arr[q]);
                    p++; q--;
                }
            }

            // recursion
            if (left < q){
                quickSortID(arr, left, q);
            }

            if (p < right){
                quickSortID(arr, p, right);
            }
        }

        void quickSortName(vector<Song> &arr, int left, int right){ 
            int p = left, q = right;
            string mid = arr[(left + right) / 2].getName();

            // partition 
            while (p <= q) {
                while (arr[p].getName() < mid)
                    p++;
                while (arr[q].getName() > mid)
                    q--;
                if (p <= q) {
                    swap(&arr[p], &arr[q]);
                    p++; q--;
                }
            }

            // recursion
            if (left < q){
                quickSortName(arr, left, q);
            }
            if (p < right){
                quickSortName(arr, p, right);
            }
        }

        void quickSortCountry(vector<Song> &arr, int left, int right){ 
            int p = left, q = right;
            string mid = arr[(left + right) / 2].getCountry();

            // partition 
            while (p <= q) {
                while (arr[p].getCountry() < mid)
                    p++;
                while (arr[q].getCountry() > mid)
                    q--;
                if (p <= q) {
                    swap(&arr[p], &arr[q]);
                    p++; q--;
                }
            }

            // recursion
            if (left < q)
                quickSortCountry(arr, left, q);
            if (p < right)
                quickSortCountry(arr, p, right);
        }

        void quickSortGenre(vector<Song> &arr, int left, int right){ 
            int p = left, q = right;
            string mid = arr[(left + right) / 2].getGenre();

            // partition 
            while (p <= q) {
                while (arr[p].getGenre() < mid)
                    p++;
                while (arr[q].getGenre() > mid)
                    q--;
                if (p <= q) {
                    swap(&arr[p], &arr[q]);
                    p++; q--;
                }
            };

            // recursion
            if (left < q)
                quickSortGenre(arr, left, q);
            if (p < right)
                quickSortGenre(arr, p, right);
        }
};
