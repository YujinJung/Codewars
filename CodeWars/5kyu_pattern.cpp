std::string zoom(int n)
{
    std::string m1 = "■";
    std::string m2 = "□";
    int flag = n % 4;
    if (flag == 1)
        flag = 0;
    else if (flag == 3)
        flag = 1;

    std::string result = "";
    int index = n;
    int oneIndex = 0;
    bool desc = false;
    for (int j = 0; j < n; ++j)
    {
        for (int k = 0; k < oneIndex; ++k)
        {
            if (flag == 0)
                result += m1;
            else if (flag == 1)
                result += m2;

            flag = (flag + 1) % 2;
        }
        for (int k = 0; k < index; ++k)
        {
            if (flag == 0)
                result += m1;
            else if (flag == 1)
                result += m2;
        }
        for (int k = 0; k < oneIndex; ++k)
        {
            flag = (flag + 1) % 2;

            if (flag == 0)
                result += m1;
            else if (flag == 1)
                result += m2;
        }

        if (desc == false && index != 1)
        {
            index -= 2;
            oneIndex++;
        }
        else
        {
            desc = true;
            index += 2;
            oneIndex--;
        }
        result.push_back('\n');
    }

    result.pop_back();

    return result;
}