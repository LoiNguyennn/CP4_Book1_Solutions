from sys import stdin

def isVowel(k):
    if k == 'a' or k == 'e' or k == 'i' or k == 'o' or k == 'u' or k == 'y':
        return True
    return False

if __name__ == '__main__':
    for line in stdin:
        sentence = line.split()
        ans = []
        for word in sentence:
            if isVowel(word[0]):
                ans.append(word + 'yay')
            else:
                for i in range(len(word)):
                    if isVowel(word[i]):
                        ans.append(word[i:] + word[:i] + 'ay')
                        break
        s = ' '.join(ans)
        print(s)