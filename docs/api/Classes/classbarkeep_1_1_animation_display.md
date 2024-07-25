# barkeep::AnimationDisplay


Displays a simple animation with a message. 


`#include <barkeep.h>`

Inherits from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)

Inherited by [`barkeep::StatusDisplay`](api/Classes/classbarkeep_1_1_status_display.md)

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using [AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle) </span>| <span class="codey">**[Style](api/Classes/classbarkeep_1_1_animation_display.md#using-style)** </span> |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[AnimationDisplay](api/Classes/classbarkeep_1_1_animation_display.md#function-animationdisplay)**(const [AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md) & cfg = {})</span><br>Constructor.  |
| <span class="codey"> </span>|  <span class="codey">  **[~AnimationDisplay](api/Classes/classbarkeep_1_1_animation_display.md#function-~animationdisplay)**()</span> |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> virtual long </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_animation_display.md#function-render_)**(bool redraw = false, const std::string & end = " ") override</span><br>Render a display: animation, progress bar, etc.  |
| <span class="codey"> [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_animation_display.md#function-default_interval_)**(bool no_tty) const</span> |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> unsigned short </span> | <span class="codey"> **[frame_](api/Classes/classbarkeep_1_1_animation_display.md#variable-frame_)**</span>  |
| <span class="codey"> [Strings](api/Namespaces/namespacebarkeep.md#using-strings) </span> | <span class="codey"> **[stills_](api/Classes/classbarkeep_1_1_animation_display.md#variable-stills_)**</span>  |
| <span class="codey"> [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span> | <span class="codey"> **[def_interval_](api/Classes/classbarkeep_1_1_animation_display.md#variable-def_interval_)**</span>  |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"></span>| <span class="codey">**[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-basedisplay)**(std::ostream * out = &std::cout, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval = [Duration](api/Namespaces/namespacebarkeep.md#using-duration){0.5}, const std::string & message = "", const std::string & format = "", bool no_tty = false)</span> |
| <span class="codey"></span>| <span class="codey">**[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-basedisplay)**(const [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) & ) = delete</span> |
| <span class="codey">[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) & </span>| <span class="codey">**[operator=](api/Classes/classbarkeep_1_1_base_display.md#function-operator=)**(const [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) & ) = delete</span> |
| <span class="codey">virtual </span>| <span class="codey">**[~BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-~basedisplay)**()</span> |
| <span class="codey">virtual void </span>| <span class="codey">**[start](api/Classes/classbarkeep_1_1_base_display.md#function-start)**()</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| <span class="codey">virtual void </span>| <span class="codey">**[show](api/Classes/classbarkeep_1_1_base_display.md#function-show)**()</span><br>Start the display.  |
| <span class="codey">virtual void </span>| <span class="codey">**[done](api/Classes/classbarkeep_1_1_base_display.md#function-done)**()</span><br>End the display.  |
| <span class="codey">std::ostream & </span>| <span class="codey">**[out](api/Classes/classbarkeep_1_1_base_display.md#function-out)**() const</span><br>Output stream to write to.  |
| <span class="codey">bool </span>| <span class="codey">**[running](api/Classes/classbarkeep_1_1_base_display.md#function-running)**() const</span><br>Return true if the display is running.  |


</span>

**Protected Functions inherited from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">long </span>| <span class="codey">**[render_message_](api/Classes/classbarkeep_1_1_base_display.md#function-render_message_)**() const</span><br>Display the message to output stream.  |
| <span class="codey"></span>| <span class="codey">**[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-basedisplay)**(std::shared_ptr< [AsyncDisplayer](api/Classes/classbarkeep_1_1_async_displayer.md) > displayer)</span> |


</span>

**Protected Attributes inherited from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">std::shared_ptr< [AsyncDisplayer](api/Classes/classbarkeep_1_1_async_displayer.md) > </span>| <span class="codey">**[displayer_](api/Classes/classbarkeep_1_1_base_display.md#variable-displayer_)** </span><br>shared across components of a composite display  |
| <span class="codey">std::string </span>| <span class="codey">**[message_](api/Classes/classbarkeep_1_1_base_display.md#variable-message_)** </span> |
| <span class="codey">std::string </span>| <span class="codey">**[format_](api/Classes/classbarkeep_1_1_base_display.md#variable-format_)** </span> |


</span>

**Friends inherited from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | <span class="codey">**[CompositeDisplay](api/Classes/classbarkeep_1_1_base_display.md#friend-compositedisplay)**</span>  |
| class | <span class="codey">**[AsyncDisplayer](api/Classes/classbarkeep_1_1_base_display.md#friend-asyncdisplayer)**</span>  |


</span>


## Public Types Documentation

### using `Style`

```cpp
using barkeep::AnimationDisplay::Style =  AnimationStyle;
```


## Public Functions Documentation

### function `AnimationDisplay`

```cpp
inline AnimationDisplay(
    const AnimationConfig & cfg = {}
)
```

Constructor. 

**Parameters**: 

  * **cfg** Animation parameters 


### function `~AnimationDisplay`

```cpp
inline ~AnimationDisplay()
```


## Protected Functions Documentation

### function `render_`

```cpp
inline virtual long render_(
    bool redraw = false,
    const std::string & end = " "
) override
```

Render a display: animation, progress bar, etc. 

**Parameters**: 

  * **redraw** If true, display is assumed to be redrawn. This, e.g. means an Animation should not increment the still frame index. 
  * **end** String to append at the end of the display. We typically add a space to space out the cursor from the content, but for composite displays, we don't want extra space between. 


**Return**: Number of `\n` characters in the display. 

**Reimplements**: [`barkeep::BaseDisplay::render_`](api/Classes/classbarkeep_1_1_base_display.md#function-render_)


**Reimplemented by**: [`barkeep::StatusDisplay::render_`](api/Classes/classbarkeep_1_1_status_display.md#function-render_)


### function `default_interval_`

```cpp
inline Duration default_interval_(
    bool no_tty
) const
```


## Protected Attributes Documentation

### variable `frame_`

```cpp
unsigned short frame_ = 0;
```


### variable `stills_`

```cpp
Strings stills_;
```


### variable `def_interval_`

```cpp
Duration def_interval_ {0.5};
```


-------------------------------