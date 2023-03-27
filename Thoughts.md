# Опишем основные составляющие языка, на основании которых далее получим грамматику

## Терминалы языка
Ключевые слова (пишутся либо все маленькими, либо капсом):
- match
- where
- return
- create
- delete
- merge
- set
- and
- or
- not

Операторы сравнения:
- <
- \>
- <=
- \>=
- ==

Другие специальные символы:
- \- (исполььзуется в паттерне связи)
- -> (исполььзуется в паттерне связи)
- <- (исполььзуется в паттерне связи)
- \-- (любая связь двух вершин)
- \:
- \(
- \)
- \[
- \]
- \{
- \}
- .
- = (присваивание)
- true
- false
- contains (добавлено мной для поиска подстрок)

## Нетерминалы языка

- variable match

    - (variable:Schema WHERE filters)
- any variable match

    (variable)

- relation match

    [variable:Relation]
    
- any relation match

    --

- MATCH querry
    
    - MATCH variable match

    - MATCH variable match relation match any variable match

    - MATCH variable match relation match variable match

    - MATCH variable match any relation match variable match

    - MATCH variable match any relation match any variable match

- integer literal

- float literal

- string literal

- RETURN expr

    - RETURN return list

- return list
    - variable
    - variable.field
    - variable, return list
    - variable.field, return list

- CREATE querry
    
    - CREATE variable match

    - CREATE variable match relation match any variable match

    - CREATE variable match relation match variable match

- value
    - literal of any type
    - variable.field

- SET expression

    SET variable.field = value

- DELETE expression

    DELETE variable

- FILTER

    value op value

- FILTER_CHAIN
    - WHERE FILTER
    - FiILTER_CHAIN FILTER