# barkeep::AsyncDisplayer


Class to handle running display loop within a worker thread. 


`#include <barkeep.h>`

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[AsyncDisplayer](api/Classes/classbarkeep_1_1_async_displayer.md#function-asyncdisplayer)**([BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) * parent, std::ostream * out, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval, bool no_tty)</span> |
| <span class="codey"> virtual </span>|  <span class="codey">  **[~AsyncDisplayer](api/Classes/classbarkeep_1_1_async_displayer.md#function-~asyncdisplayer)**()</span> |
| <span class="codey"> void </span>|  <span class="codey">  **[out](api/Classes/classbarkeep_1_1_async_displayer.md#function-out)**(std::ostream * out)</span><br>Set output stream to write to.  |
| <span class="codey"> void </span>|  <span class="codey">  **[parent](api/Classes/classbarkeep_1_1_async_displayer.md#function-parent)**([BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) * parent)</span><br>Set parent display.  |
| <span class="codey"> void </span>|  <span class="codey">  **[interval](api/Classes/classbarkeep_1_1_async_displayer.md#function-interval)**([Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval)</span><br>Set interval.  |
| <span class="codey"> [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>|  <span class="codey">  **[interval](api/Classes/classbarkeep_1_1_async_displayer.md#function-interval)**() const</span><br>Get interval.  |
| <span class="codey"> void </span>|  <span class="codey">  **[no_tty](api/Classes/classbarkeep_1_1_async_displayer.md#function-no_tty)**(bool no_tty)</span><br>Set no-tty mode.  |
| <span class="codey"> bool </span>|  <span class="codey">  **[no_tty](api/Classes/classbarkeep_1_1_async_displayer.md#function-no_tty)**() const</span><br>Get no-tty mode.  |
| <span class="codey"> void </span>|  <span class="codey">  **[notify](api/Classes/classbarkeep_1_1_async_displayer.md#function-notify)**()</span><br>Notify completion condition variable.  |
| <span class="codey"> std::ostream & </span>|  <span class="codey">  **[out](api/Classes/classbarkeep_1_1_async_displayer.md#function-out)**()</span><br>Output stream to write to.  |
| <span class="codey"> bool </span>|  <span class="codey">  **[running](api/Classes/classbarkeep_1_1_async_displayer.md#function-running)**() const</span><br>Return true if the display is running.  |
| <span class="codey"> void </span>|  <span class="codey">  **[show](api/Classes/classbarkeep_1_1_async_displayer.md#function-show)**()</span><br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| <span class="codey"> virtual void </span>|  <span class="codey">  **[done](api/Classes/classbarkeep_1_1_async_displayer.md#function-done)**()</span><br>End the display.  |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> void </span>| <span class="codey"> **[display_](api/Classes/classbarkeep_1_1_async_displayer.md#function-display_)**(bool redraw = false)</span><br>Display everything (message, maybe with animation, progress bar, etc).  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[join](api/Classes/classbarkeep_1_1_async_displayer.md#function-join)**()</span><br>Join the display thread. Protected because python bindings need to override to handle GIL.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::ostream * </span> | <span class="codey"> **[out_](api/Classes/classbarkeep_1_1_async_displayer.md#variable-out_)**</span> <br>output stream to write  |
| <span class="codey"> [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) * </span> | <span class="codey"> **[parent_](api/Classes/classbarkeep_1_1_async_displayer.md#variable-parent_)**</span> <br>parent display to render which owns this  |
| <span class="codey"> std::unique_ptr< std::thread > </span> | <span class="codey"> **[displayer_thread_](api/Classes/classbarkeep_1_1_async_displayer.md#variable-displayer_thread_)**</span>  |
| <span class="codey"> std::condition_variable </span> | <span class="codey"> **[done_cv_](api/Classes/classbarkeep_1_1_async_displayer.md#variable-done_cv_)**</span>  |
| <span class="codey"> std::mutex </span> | <span class="codey"> **[done_m_](api/Classes/classbarkeep_1_1_async_displayer.md#variable-done_m_)**</span>  |
| <span class="codey"> std::atomic< bool > </span> | <span class="codey"> **[done_](api/Classes/classbarkeep_1_1_async_displayer.md#variable-done_)**</span> <br>if true, display can be stopped  |
| <span class="codey"> long </span> | <span class="codey"> **[last_num_newlines_](api/Classes/classbarkeep_1_1_async_displayer.md#variable-last_num_newlines_)**</span>  |
| <span class="codey"> [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span> | <span class="codey"> **[interval_](api/Classes/classbarkeep_1_1_async_displayer.md#variable-interval_)**</span> <br>interval to refresh and check if complete  |
| <span class="codey"> bool </span> | <span class="codey"> **[no_tty_](api/Classes/classbarkeep_1_1_async_displayer.md#variable-no_tty_)**</span> <br>true if output is not a tty  |


</span>

## Public Functions Documentation

### function `AsyncDisplayer`

```cpp
inline AsyncDisplayer(
    BaseDisplay * parent,
    std::ostream * out,
    Duration interval,
    bool no_tty
)
```


### function `~AsyncDisplayer`

```cpp
inline virtual ~AsyncDisplayer()
```


### function `out`

```cpp
inline void out(
    std::ostream * out
)
```

Set output stream to write to. 

### function `parent`

```cpp
inline void parent(
    BaseDisplay * parent
)
```

Set parent display. 

### function `interval`

```cpp
inline void interval(
    Duration interval
)
```

Set interval. 

### function `interval`

```cpp
inline Duration interval() const
```

Get interval. 

### function `no_tty`

```cpp
inline void no_tty(
    bool no_tty
)
```

Set no-tty mode. 

### function `no_tty`

```cpp
inline bool no_tty() const
```

Get no-tty mode. 

### function `notify`

```cpp
inline void notify()
```

Notify completion condition variable. 

### function `out`

```cpp
inline std::ostream & out()
```

Output stream to write to. 

### function `running`

```cpp
inline bool running() const
```

Return true if the display is running. 

### function `show`

```cpp
inline void show()
```

Start the display. This starts writing the display in the output stream, and computing speed if applicable. 

### function `done`

```cpp
inline virtual void done()
```

End the display. 

## Protected Functions Documentation

### function `display_`

```cpp
inline void display_(
    bool redraw = false
)
```

Display everything (message, maybe with animation, progress bar, etc). 

**Parameters**: 

  * **redraw** If true, display is assumed to be redrawn. This, e.g. means an Animation should not increment the still frame index. 


### function `join`

```cpp
inline virtual void join()
```

Join the display thread. Protected because python bindings need to override to handle GIL. 

## Protected Attributes Documentation

### variable `out_`

```cpp
std::ostream * out_ = &std::cout;
```

output stream to write 

### variable `parent_`

```cpp
BaseDisplay * parent_ = nullptr;
```

parent display to render which owns this 

### variable `displayer_thread_`

```cpp
std::unique_ptr< std::thread > displayer_thread_;
```


### variable `done_cv_`

```cpp
std::condition_variable done_cv_;
```


### variable `done_m_`

```cpp
std::mutex done_m_;
```


### variable `done_`

```cpp
std::atomic< bool > done_ = false;
```

if true, display can be stopped 

### variable `last_num_newlines_`

```cpp
long last_num_newlines_ = 0;
```


### variable `interval_`

```cpp
Duration interval_;
```

interval to refresh and check if complete 

### variable `no_tty_`

```cpp
bool no_tty_ = false;
```

true if output is not a tty 

-------------------------------