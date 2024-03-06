- File input.txt và output.txt sẽ ở chung thư mục với file code

- Định dạng đầu vào của file input.txt:
  + Mỗi dòng sẽ thể hiện cho đỉnh và các đỉnh mà nó đi tới, cách nhau bởi dấu cách (space) (trừ dòng cuối cùng sẽ hơi khác)
    + giá trị h của mỗi đỉnh sẽ được điền ngay sau tên đỉnh đó cách bởi dấu "-"
    + ngay sau giá trị h sẽ là khoảng cách từ đỉnh đang xét tới các đỉnh mà nó đi tới
	(ví dụ: C-15 H-10-6: 10 là giá trị h của đỉnh, 6 là khoảng cách từ đỉnh C -> H)
  + Dòng cuối cùng là dòng thể hiện cho đỉnh bắt đầu và đỉnh đích, được nhận biết bằng cách gõ kí tự ">" ở đầu dòng

- Ví dụ về định dạng đầu vào file input:
   A-14 C-15-9 D-6-7 E-8-13 F-7-20   ( A sẽ là đỉnh trong đồ thị và tiếp sau C D E F sẽ là các đỉnh kề mà đỉnh A có thể đi tới )
   C-15 H-10-6   ( C sẽ là đỉnh trong đồ thị và tiếp sau H sẽ là đỉnh mà đỉnh B có thể đi tới )
   D-6 H-10-8 E-8-4
   E-8 K-2-4 I-4-3
   F-7 G-12-4 I-4-6
   H-10 K-2-5
   K-2 B-0-6
   I-4 K-2-9 B-0-5
   B-0
   G-12
   > A B   ( Dòng cuối thể hiện cho hai đỉnh bắt đầu và đích, cần gõ kí tự ">" ở đầu để có thể đọc đúng dữ liệu )
