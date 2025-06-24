import { Prism } from "react-syntax-highlighter";
import githubData from "@config/github-data";
import { tomorrow } from "react-syntax-highlighter/dist/cjs/styles/prism";
import type { ReactNode } from "react";

interface CodeSnippetProps {
  source: string;
  sourcePath?: string;
  language?: string;
  startMarker?: string;
  endMarker?: string;
  commentStyle?: string;
}

function InnerPre({ children }: { children: ReactNode }) {
  return (
    <figure className="frame not-content">
      <pre>{children}</pre>
    </figure>
  );
}

function InnerCode({ children, className }: { children: ReactNode; className?: string }) {
  return <code className={className}>{children}</code>;
}

export default function CodeSnippet({ source, language = "cpp", commentStyle = "//", startMarker, endMarker, sourcePath }: CodeSnippetProps) {
  const lines = source.split("\n").map((l, i) => [i, l] satisfies [number, string]);
  let snippet: string;
  let startLineNum: number;
  let endLineNum: number;

  if (!(startMarker || endMarker)) {
    snippet = source;
    startLineNum = 1;
    endLineNum = lines.length + 1;
  }

  const startLine = lines.filter(([i, l]) => l.match(new RegExp(`^\\s*${commentStyle}\\s*${startMarker}\\s*$`)));
  startLineNum = startLine.length ? startLine[0][0] : -1;

  const endLine = lines.filter(([i, l]) => l.match(new RegExp(`^\\s*${commentStyle}\\s*${endMarker}\\s*$`)));
  endLineNum = endLine.length ? endLine[0][0] : lines.length + 1;

  snippet = lines
    .filter(([i, _]) => i > startLineNum && i < endLineNum)
    .map(([_, l]) => l)
    .join("\n");

  startLineNum += 2;

  const url = [githubData.repositoryAddress(), "blob", githubData.deploymentBranch, "tab", sourcePath, `#L${startLineNum}-L${endLineNum}`].join("/");

  // const title = sourcePath ? <a href={url}>{sourcePath}</a> : undefined;

  return (
    <Prism
      language={language}
      showLineNumbers
      startingLineNumber={startLineNum}
      CodeTag={InnerCode}
      style={tomorrow}
      useInlineStyles={false}
      lineNumberStyle={{
        paddingRight: "0.5em",
        minWidth: "2em",
      }}
    >
      {snippet}
    </Prism>
  );
}
