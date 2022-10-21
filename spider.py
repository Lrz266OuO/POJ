
from cgitb import html
from email import header
from fileinput import filename
import requests,re,json,os
from bs4 import BeautifulSoup

HOST = 'http://poj.org/'

def getHTMLText(url):
    try:
        headers = {'User-Agent':'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'}
        r = requests.get(url,timeout=30,headers = headers)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ''

def getSoupObj(url):
    try:
        html = getHTMLText(url)
        soup = BeautifulSoup(html,'html.parser')
        return soup
    except:
        print('\nError: failed to get the Soup object')
        return None

def getProblemList(url):
    soup = getSoupObj(url)
    list = []
    tmps = soup('a',{'href':re.compile(r'problem\?id=[\d]*')})
    for i in tmps:
        list.append(i.attrs['href'])
    return list


def getContent(url):
    soup = getSoupObj(url)
    paras_tmp = soup.select('tr[align="center"]')
    paras = paras_tmp[0:]
    # print(paras)
    return paras


def saveFile(text):
    fname = "problem.txt"
    f = open(fname, 'a', encoding='utf-8')
    for t in text:
        # print(type(t.get_text()))
        # print(t.get_text())
        if len(t) > 0:
            count = 0
            for tmp in t:
                if count >= 2:
                    break
                f.writelines("| " + tmp.get_text() + " ")
                count = count + 1
            f.writelines("|n|\n")
            # f.writelines(t.get_text() + "\n")
    f.close()


def getInfo(url):
    global HOST
    soup = getSoupObj(url)
    links = soup('a',{'href':re.compile(r'\?volume=[\d]*')})
    pageList = []
    for i in links:
        pageList.append(i.attrs['href'])
    pageList = sorted(set(pageList),key=pageList.index)
    # print(pageList)
    for i in pageList:
        content = getContent(HOST + i)
        saveFile(content)
        

if __name__=="__main__":
    requestUrl = HOST + 'problemlist'
    getInfo(requestUrl)
