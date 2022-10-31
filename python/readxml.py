import xml.etree.ElementTree as elemTree
import pymysql

tree = elemTree.parse('data3.xml')

data = tree.find('./data').findall('item')


xml_arr =[]
xml_dictionary ={}

for item in data:
    xml_dictionary['연번'] = item.find('./col[@name="연번"]').text
    try:
        xml_dictionary['서명']=item.find('./col[@name="서명"]').text
    except:
        xml_dictionary['서명']=''
    xml_dictionary['가격']=item.find('./col[@name="가격"]').text
    xml_arr.append(xml_dictionary)
    xml_dictionary={}

    conn = pymysql.connect(host='localhost',
                           user='root',
                           password='1234',
                           db='myprojectdb',
                           charset='utf8')

sql = 'insert into book values(%d, "%s", %d)'
cur = conn.cursor()
for item in xml_arr:
          cur.execute(sql % ( ((int)(item['연번'])) + 4200, item['서명'],
                               (int)(item['가격']) ))
conn.commit()
conn.close()

