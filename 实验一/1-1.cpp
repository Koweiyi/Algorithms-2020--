#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int cnt_tree;
    char name[20];
    string pro;
    int id;
    bool operator<(const Student s) const
    {
        return cnt_tree < s.cnt_tree;
    }
};

bool read_in_Student(Student &student, string pro)
{
    cin >> student.id;
    if (student.id == -1)
        return false;
    cin >> student.name >> student.cnt_tree;
    student.pro = pro;
    return true;
}

void input_init(vector<Student> &students, map<string, int> &record_pro, vector<string> &pros)
{
    cout << "请输入信息：(#号结束所有专业输入 ，-1结束某一专业输入)" << endl;
    string pro;
    while (cin >> pro && pro != "#")
    {
        pros.push_back(pro);
        int cnt = 0;
        bool status = true;
        while (true)
        {
            Student s;
            status = read_in_Student(s, pro);
            if (!status)
                break;
            students.push_back(s);
            cnt++;
        }
        record_pro[pro] = cnt;
    }
}

void print_Students_beforeSort(vector<Student> students, map<string, int> record_pro, vector<string> pros)
{
    int printed_count = 0;
    cout << "未排序前：" << endl;
    for (string pro : pros)
    {
        map<string, int>::iterator p = record_pro.find(pro);
        cout << p->first << endl;
        for (int i = 0; i < p->second; i++)
        {
            cout << "\t" << students[printed_count].id << "\t" << students[printed_count].name << "\t" << students[printed_count].cnt_tree << endl;
            printed_count++;
        }
    }
}

void print_Students_afterSort(vector<Student> students)
{
    cout << "\n\n-------------------------------------------------------------\n\n排序后:\n"
         << endl;
    cout << "   专业\t\t  学号\t\t姓名\t植树数" << endl;
    for (Student stu : students)
    {
        cout << stu.pro << "\t" << stu.id << "\t" << stu.name << "\t  " << stu.cnt_tree << endl;
    }
    cout << "\n-------------------------------------------------------------\n\n";
}

void quickSort(vector<Student> &Vec, int l, int r)
{
    Student mid = Vec[l + (r - l) / 2];
    int i = l, j = r;
    do
    {
        while (Vec[i] < mid && i < r)
            i++;
        while (mid < Vec[j] && j > l)
            j--;
        if (i <= j)
            swap(Vec[i++], Vec[j--]);
    } while (i <= j);
    if (i < r)
        quickSort(Vec, i, r);
    if (j > l)
        quickSort(Vec, l, j);
}

int bineary_search(vector<Student> students, int target, int left, int right)
{
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if (students[mid].cnt_tree == target)
        return mid;
    else if (students[mid].cnt_tree > target)
        return bineary_search(students, target, left, mid - 1);
    else
        return bineary_search(students, target, mid + 1, right);
}

void bineary_search(vector<Student> students, int target)
{
    int index = bineary_search(students, target, 0, students.size() - 1);
    if (index == -1)
        cout << "没有学生种植此数量的树木" << endl;

    while (index > 0)
    {
        if (students[index - 1].cnt_tree == target)
            index--;
        else
            break;
    }
    for (int i = 1; students[index].cnt_tree == target; i++, index++)
    {
        cout << "该生排在第" << index + 1 << "位,"
             << "查找" << i << "次成功！ " << students[index].pro << "   " << students[index].id << "   " << students[index].name << "   " << students[index].cnt_tree << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<Student> students;
    map<string, int> record_pro;
    vector<string> pros;
    input_init(students, record_pro, pros);
    //保留原始数据
    vector<Student> copy_stu;
    for (Student stu : students)
        copy_stu.push_back(stu);

    print_Students_beforeSort(students, record_pro, pros);
    quickSort(copy_stu, 0, students.size() - 1);
    print_Students_afterSort(copy_stu);

    int tree_cnt;
    cout << "请输入要查找的植树数量:\t";
    cin >> tree_cnt;

    bineary_search(copy_stu, tree_cnt);
    system("pause");
    return 0;
}
