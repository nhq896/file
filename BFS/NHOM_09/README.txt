- File input.txt và output.txt sẽ ở chung thư mục với file code

- Định dạng đầu vào của file input.txt:
  + Mỗi dòng sẽ thể hiện cho đỉnh và các đỉnh kề của nó, cách nhau bởi dấu cách (space) (trừ dòng cuối cùng sẽ hơi khác)
  + Dòng cuối cùng là dòng thể hiện cho đỉnh bắt đầu và đỉnh đích, được nhận biết bằng cách gõ kí tự ">" ở đầu dòng

- Ví dụ về định dạng đầu vào file input:
   A B C D  ( A sẽ là đỉnh trong đồ thị và tiếp sau B C D sẽ là các đỉnh kề với đỉnh A )
   B I G    ( B sẽ là đỉnh trong đồ thị và tiếp sau I G sẽ là các đỉnh kề với đỉnh B )
   C E F
   D C F
   E G K
   F K
   I G
   > A G  ( Dòng cuối thể hiện cho hai đỉnh bắt đầu và đích, cần gõ kí tự ">" ở đầu để có thể đọc đúng dữ liệu )