# barkeep::CompositeDisplay


Creates a composite display out of multiple child displays to show them together. For instance, you can combine two Counter objects, or a Counter and a ProgressBar to concurrently monitor two variables. 


`#include <barkeep.h>`

Inherits from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[CompositeDisplay](api/Classes/classbarkeep_1_1_composite_display.md#function-compositedisplay)**(const std::vector< std::shared_ptr< [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) > > & displays, std::string delim = " ")</span> |
| <span class="codey"> </span>|  <span class="codey">  **[~CompositeDisplay](api/Classes/classbarkeep_1_1_composite_display.md#function-~compositedisplay)**()</span> |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> virtual long </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_composite_display.md#function-render_)**(bool redraw = false, const std::string & end = " ") override</span><br>Render a display: animation, progress bar, etc.  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_composite_display.md#function-start)**() override</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::string </span> | <span class="codey"> **[delim_](api/Classes/classbarkeep_1_1_composite_display.md#variable-delim_)**</span> <br>delimiter between displays  |
| <span class="codey"> std::vector< std::shared_ptr< [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) > > </span> | <span class="codey"> **[displays_](api/Classes/classbarkeep_1_1_composite_display.md#variable-displays_)**</span> <br>child displays to show  |


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
| class | <span class="codey">**[AsyncDisplayer](api/Classes/classbarkeep_1_1_base_display.md#friend-asyncdisplayer)**</span>  |


</span>


## Public Functions Documentation

### function `CompositeDisplay`

```cpp
inline CompositeDisplay(
    const std::vector< std::shared_ptr< BaseDisplay > > & displays,
    std::string delim = " "
)
```


### function `~CompositeDisplay`

```cpp
inline ~CompositeDisplay()
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


### function `start`

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [`barkeep::BaseDisplay::start`](api/Classes/classbarkeep_1_1_base_display.md#function-start)


## Protected Attributes Documentation

### variable `delim_`

```cpp
std::string delim_ = " ";
```

delimiter between displays 

### variable `displays_`

```cpp
std::vector< std::shared_ptr< BaseDisplay > > displays_;
```

child displays to show 

-------------------------------