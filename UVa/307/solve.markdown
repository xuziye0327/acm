﻿##solve##
DFS + 剪枝。

DFS 容易写， 这剪枝就有点玄妙了。

一、 先把木棍长度按从大到小排序， 这样可以减少很多递归次数， 也方便下面的剪枝。

二、 拼成的木棍长度一定是所有木棍长度之和的约数， 这个也很简单。

三、 如果当前木棍和上一个木棍长度一样， 那么如果用上一个木棍匹配失败的话这个也不用考虑。

四、 如果当前木棍能和已选的木棍拼成和已经拼好的木棍长度一样的话， 如果从这搜索失败的话， 余下的也不用考虑了。 假设再考虑下一个木棍， 如果这个木棍和上一个木棍长度一样的话， 可以跳过； 如果不一样， 说明上一个木棍还没有被使用， 就算再遍历一次上一个木棍， 还是不可能成功， 所以可以不用遍历。

五、 如果当前木棍是新的木棍的第一截， 如果不用这个木棍， 那么其他的也不用考虑， 原因同上。
