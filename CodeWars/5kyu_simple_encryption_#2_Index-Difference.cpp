class Kata
{
  private:
    std::map<char, int> m;
    std::vector<char> v;

  public:
    Kata()
    {
        Init();
    }
    void Init()
    {
        int index = 0;
        // Upper 65 90
        // Lower 97 122

        for (char i = 'A'; i <= 'Z'; i++, index++)
        {
            m[i] = index;
            v.push_back(i);
        }

        std::cout << std::endl;
        for (char i = 'a'; i <= 'z'; i++, index++)
        {
            m[i] = index;
            v.push_back(i);
        }

        std::cout << std::endl;
        for (char i = '0'; i <= '9'; i++, index++)
        {
            m[i] = index;
            v.push_back(i);
        }

        m['.'] = index++;
        m[','] = index++;
        m[':'] = index++;
        m[';'] = index++;
        m['-'] = index++;
        m['?'] = index++;
        m['!'] = index++;
        m[' '] = index++;
        m[39] = index++;
        m['('] = index++;
        m[')'] = index++;
        m['$'] = index++;
        m['%'] = index++;
        m['&'] = index++;
        m['"'] = index++;

        v.push_back('.');
        v.push_back(',');
        v.push_back(':');
        v.push_back(';');
        v.push_back('-');
        v.push_back('?');
        v.push_back('!');
        v.push_back(' ');
        v.push_back(39);
        v.push_back('(');
        v.push_back(')');
        v.push_back('$');
        v.push_back('%');
        v.push_back('&');
        v.push_back('"');
    }
    std::string encrypt(std::string text)
    {
        // even switch case
        int index = 0;
        std::string result;
        char pre;

        for (auto x : text)
        {
            if (index == 0)
            {
                pre = x;
                result.push_back(v.at(77 - m.at(x) - 1));
                index++;

                continue;
            }
            if (index % 2 == 0)
            {
                char pre_ = pre;
                pre = x;

                int k = m.at(pre_) - m.at(x);
                if (k < 0)
                    k += 77;
                result.push_back(v.at(k));
            }
            else if (index % 2 == 1)
            {
                // Switch Case
                char temp = x;
                char pre_ = pre;
                // Switch
                if (m.at(x) >= 26 && m.at(x) <= 51)
                    temp = v.at(m.at(x) - 26);
                else if (m.at(x) < 26)
                    temp = v.at(m.at(x) + 26);

                pre = temp;

                int k = m[pre_] - m[temp];
                std::cout << m[pre_] << " " << m.at(temp) << " " << k << std::endl;
                if (k < 0)
                    k += 77;
                result.push_back(v.at(k));
            }
            index++;
        }

        return result;
    }

    std::string decrypt(std::string encryptedText)
    {
        // pre - cur
        // pre - cur + 77
        // cur = pre - x
        // cur = pre - x + 77
        char pre;
        std::string result;
        int index = 0;

        for (auto x : encryptedText)
        {
            if (index == 0)
            {
                pre = v.at(77 - m.at(x) - 1);
                result.push_back(pre);
                index++;

                continue;
            }

            if (index % 2 == 0)
            {
                int k = m.at(pre) - m.at(x);
                if (k < 0)
                    k += 77;
                result.push_back(v.at(k));
                pre = v.at(k);
            }
            else if (index % 2 == 1)
            {
                int k = m.at(pre) - m.at(x);
                if (k < 0)
                    k += 77;
                std::cout << "k: " << v.at(k) << std::endl;

                pre = v.at(k);

                char temp = pre;
                // Switch
                if (m.at(pre) >= 26 && m.at(pre) <= 51)
                    temp = v.at(m.at(pre) - 26);
                else if (m.at(pre) < 26)
                    temp = v.at(m.at(pre) + 26);
                result.push_back(temp);
            }
            index++;
        }

        return result;
    }
};