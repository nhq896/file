- File input.txt và output.txt sẽ ở chung thư mục với file code

- Định dạng đầu vào của file input.txt:
  + Mỗi dòng sẽ thể hiện cho đỉnh và các đỉnh mà nó đi tới, cách nhau bởi dấu cách (space) (trừ dòng cuối cùng sẽ hơi khác)
     + giá trị của mỗi đỉnh sẽ được điền ngay sau tên đỉnh đó cách bỏi dấu "-"
  + Dòng cuối cùng là dòng thể hiện cho đỉnh bắt đầu và đỉnh đích, được nhận biết bằng cách gõ kí tự ">" ở đầu dòng

- Ví dụ về định dạng đầu vào file input:
   A-20 C-15 D-6 E-7  ( A-20 sẽ là đỉnh có giá trị 20 trong đồ thị và tiếp sau C-15 D-6 E-7 sẽ là các đỉnh mà đỉnh A đi tới được)
   C-15 F-10   ( C-15 sẽ là đỉnh có giá trị 15 trong đồ thị và tiếp sau F-10 sẽ là đỉnh mà đỉnh C đi tới được )
   D-6 F-10 I-8
   E-7 G-5 K-12
   F-10 B-0
   K-12
   I-8 G-5 B-0
   G-5 H-3 B-0
   H-3 B-0
   B-0
   > A B   ( Dòng cuối thể hiện cho hai đỉnh bắt đầu và đích, cần gõ kí tự ">" ở đầu để có thể đọc đúng dữ liệu )
