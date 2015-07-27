<GameProjectFile>
  <PropertyGroup Type="Scene" Name="TitleScene" ID="cda91223-c9d9-4c26-b05d-edc5d26c3654" Version="2.3.1.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="1799" Speed="0.5000">
        <Timeline ActionTag="-347546047" Property="RotationSkew">
          <ScaleFrame FrameIndex="1799" X="360.0000" Y="360.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-70549337" Property="Position">
          <PointFrame FrameIndex="769" X="568.0000" Y="512.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-70549337" Property="Scale">
          <ScaleFrame FrameIndex="769" X="2.0000" Y="2.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-70549337" Property="AnchorPoint">
          <ScaleFrame FrameIndex="769" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="37" ctype="GameNodeObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="title_back_1" ActionTag="1682281789" Tag="38" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" TopMargin="-104.5280" BottomMargin="-107.4720" ctype="SpriteObjectData">
            <Size X="1136.0000" Y="852.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="318.5280" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4977" />
            <PreSize X="2.0000" Y="2.6625" />
            <FileData Type="Normal" Path="back/title_back.jpg" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="glove" ActionTag="-347546047" Tag="113" Rotation="360.0000" RotationSkewX="360.0000" RotationSkewY="360.0000" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="304.0000" RightMargin="304.0000" TopMargin="313.2900" BottomMargin="-197.2900" ctype="SpriteObjectData">
            <Size X="528.0000" Y="524.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="64.7100" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.1011" />
            <PreSize X="0.4648" Y="0.8188" />
            <FileData Type="Normal" Path="back/glove.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Start" ActionTag="-341345126" Tag="39" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="408.0000" RightMargin="408.0000" TopMargin="270.0000" BottomMargin="270.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="163" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="320.0000" Y="100.0000" />
            <Children>
              <AbstractNodeData Name="label" ActionTag="566219024" Tag="40" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="86.0000" RightMargin="86.0000" TopMargin="11.5000" BottomMargin="11.5000" LabelText="Start" ctype="TextBMFontObjectData">
                <Size X="148.0000" Y="77.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="160.0000" Y="50.0000" />
                <Scale ScaleX="0.9000" ScaleY="0.9000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.4625" Y="0.7700" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.2817" Y="0.1563" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="ui/button2.png" Plist="" />
            <NormalFileData Type="Normal" Path="ui/button.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Language" ActionTag="1003370739" Tag="41" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="408.0000" RightMargin="408.0000" TopMargin="390.0000" BottomMargin="150.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="163" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="320.0000" Y="100.0000" />
            <Children>
              <AbstractNodeData Name="label" ActionTag="1730327379" Tag="42" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="16.0000" RightMargin="16.0000" TopMargin="11.5000" BottomMargin="11.5000" LabelText="Language" ctype="TextBMFontObjectData">
                <Size X="288.0000" Y="77.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="160.0000" Y="50.0000" />
                <Scale ScaleX="0.9000" ScaleY="0.9000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.9000" Y="0.7700" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="200.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.3125" />
            <PreSize X="0.2817" Y="0.1563" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="ui/button2.png" Plist="" />
            <NormalFileData Type="Normal" Path="ui/button.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Credit" ActionTag="1815142567" Tag="43" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="408.0000" RightMargin="408.0000" TopMargin="510.0000" BottomMargin="30.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="163" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="320.0000" Y="100.0000" />
            <Children>
              <AbstractNodeData Name="label" ActionTag="500014900" Tag="44" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="65.5000" RightMargin="65.5000" TopMargin="11.5000" BottomMargin="11.5000" LabelText="Credit" ctype="TextBMFontObjectData">
                <Size X="189.0000" Y="77.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="160.0000" Y="50.0000" />
                <Scale ScaleX="0.9000" ScaleY="0.9000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.5906" Y="0.7700" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="80.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.1250" />
            <PreSize X="0.2817" Y="0.1563" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="ui/button2.png" Plist="" />
            <NormalFileData Type="Normal" Path="ui/button.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="BitmapFontLabel_1" ActionTag="-70549337" Tag="12" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="354.0000" RightMargin="354.0000" TopMargin="89.5000" BottomMargin="473.5000" LabelText="OH MY GOD!" ctype="TextBMFontObjectData">
            <Size X="428.0000" Y="77.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="512.0000" />
            <Scale ScaleX="2.0000" ScaleY="2.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.8000" />
            <PreSize X="0.3768" Y="0.1203" />
            <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>