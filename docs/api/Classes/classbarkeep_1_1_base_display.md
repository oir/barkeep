# barkeep::BaseDisplay


Base class to handle all asynchronous displays. 


`#include <barkeep.h>`

Inherited by [`barkeep::AnimationDisplay`](api/Classes/classbarkeep_1_1_animation_display.md), [`barkeep::CompositeDisplay`](api/Classes/classbarkeep_1_1_composite_display.md), [`barkeep::CounterDisplay< Progress >`](api/Classes/classbarkeep_1_1_counter_display.md), [`barkeep::ProgressBarDisplay< Progress >`](api/Classes/classbarkeep_1_1_progress_bar_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-basedisplay)**(std::ostream * out = &std::cout, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval = [Duration](api/Namespaces/namespacebarkeep.md#using-duration){0.5}, const std::string & message = "", const std::string & format = "", bool no_tty = false)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-basedisplay)**(const [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) & ) = delete</span> |
| <span class="codey"> [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) & </span>|  <span class="codey">  **[operator=](api/Classes/classbarkeep_1_1_base_display.md#function-operator=)**(const [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) & ) = delete</span> |
| <span class="codey"> virtual </span>|  <span class="codey">  **[~BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-~basedisplay)**()</span> |
| <span class="codey"> virtual void </span>|  <span class="codey">  **[start](api/Classes/classbarkeep_1_1_base_display.md#function-start)**()</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| <span class="codey"> virtual void </span>|  <span class="codey">  **[show](api/Classes/classbarkeep_1_1_base_display.md#function-show)**()</span><br>Start the display.  |
| <span class="codey"> virtual void </span>|  <span class="codey">  **[done](api/Classes/classbarkeep_1_1_base_display.md#function-done)**()</span><br>End the display.  |
| <span class="codey"> std::ostream & </span>|  <span class="codey">  **[out](api/Classes/classbarkeep_1_1_base_display.md#function-out)**() const</span><br>Output stream to write to.  |
| <span class="codey"> bool </span>|  <span class="codey">  **[running](api/Classes/classbarkeep_1_1_base_display.md#function-running)**() const</span><br>Return true if the display is running.  |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> virtual long </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_base_display.md#function-render_)**(bool redraw = false, const std::string & end = " ") = 0</span><br>Render a display: animation, progress bar, etc.  |
| <span class="codey"> long </span>| <span class="codey"> **[render_message_](api/Classes/classbarkeep_1_1_base_display.md#function-render_message_)**() const</span><br>Display the message to output stream.  |
| <span class="codey"> </span>| <span class="codey"> **[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-basedisplay)**(std::shared_ptr< [AsyncDisplayer](api/Classes/classbarkeep_1_1_async_displayer.md) > displayer)</span> |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::shared_ptr< [AsyncDisplayer](api/Classes/classbarkeep_1_1_async_displayer.md) > </span> | <span class="codey"> **[displayer_](api/Classes/classbarkeep_1_1_base_display.md#variable-displayer_)**</span> <br>shared across components of a composite display  |
| <span class="codey"> std::string </span> | <span class="codey"> **[message_](api/Classes/classbarkeep_1_1_base_display.md#variable-message_)**</span>  |
| <span class="codey"> std::string </span> | <span class="codey"> **[format_](api/Classes/classbarkeep_1_1_base_display.md#variable-format_)**</span>  |


</span>

## Friends

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | <span class="codey"> **[CompositeDisplay](api/Classes/classbarkeep_1_1_base_display.md#friend-compositedisplay)** </span> |
| class | <span class="codey"> **[AsyncDisplayer](api/Classes/classbarkeep_1_1_base_display.md#friend-asyncdisplayer)** </span> |


</span>

## Public Functions Documentation

### function `BaseDisplay`

```cpp
inline BaseDisplay(
    std::ostream * out = &std::cout,
    Duration interval = Duration{0.5},
    const std::string & message = "",
    const std::string & format = "",
    bool no_tty = false
)
```


### function `BaseDisplay`

```cpp
BaseDisplay(
    const BaseDisplay & 
) = delete
```


### function `operator=`

```cpp
BaseDisplay & operator=(
    const BaseDisplay & 
) = delete
```


### function `~BaseDisplay`

```cpp
inline virtual ~BaseDisplay()
```


### function `start`

```cpp
inline virtual void start()
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplemented by**: [`barkeep::CounterDisplay::start`](api/Classes/classbarkeep_1_1_counter_display.md#function-start), [`barkeep::ProgressBarDisplay::start`](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-start), [`barkeep::CompositeDisplay::start`](api/Classes/classbarkeep_1_1_composite_display.md#function-start)


### function `show`

```cpp
inline virtual void show()
```

Start the display. 

### function `done`

```cpp
inline virtual void done()
```

End the display. 

### function `out`

```cpp
inline std::ostream & out() const
```

Output stream to write to. 

### function `running`

```cpp
inline bool running() const
```

Return true if the display is running. 

## Protected Functions Documentation

### function `render_`

```cpp
virtual long render_(
    bool redraw = false,
    const std::string & end = " "
) = 0
```

Render a display: animation, progress bar, etc. 

**Parameters**: 

  * **redraw** If true, display is assumed to be redrawn. This, e.g. means an Animation should not increment the still frame index. 
  * **end** String to append at the end of the display. We typically add a space to space out the cursor from the content, but for composite displays, we don't want extra space between. 


**Return**: Number of `\n` characters in the display. 

**Reimplemented by**: [`barkeep::AnimationDisplay::render_`](api/Classes/classbarkeep_1_1_animation_display.md#function-render_), [`barkeep::StatusDisplay::render_`](api/Classes/classbarkeep_1_1_status_display.md#function-render_), [`barkeep::CompositeDisplay::render_`](api/Classes/classbarkeep_1_1_composite_display.md#function-render_), [`barkeep::CounterDisplay::render_`](api/Classes/classbarkeep_1_1_counter_display.md#function-render_), [`barkeep::ProgressBarDisplay::render_`](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-render_)


### function `render_message_`

```cpp
inline long render_message_() const
```

Display the message to output stream. 

**Return**: Number of `\n` characters in the message. 

### function `BaseDisplay`

```cpp
inline BaseDisplay(
    std::shared_ptr< AsyncDisplayer > displayer
)
```


## Protected Attributes Documentation

### variable `displayer_`

```cpp
std::shared_ptr< AsyncDisplayer > displayer_;
```

shared across components of a composite display 

### variable `message_`

```cpp
std::string message_;
```


### variable `format_`

```cpp
std::string format_;
```


## Friends

### friend `CompositeDisplay`

```cpp
friend class CompositeDisplay(
    CompositeDisplay 
);
```


### friend `AsyncDisplayer`

```cpp
friend class AsyncDisplayer(
    AsyncDisplayer 
);
```


-------------------------------